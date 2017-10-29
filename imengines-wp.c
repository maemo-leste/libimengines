/**
  @file imengines-wp.c

  Copyright (C) 2017 Jonathan Wilson

  @author Jonathan wilson <jfwfreo@tpgi.com.au>

  This library is free software; you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License version 2.1 as
  published by the Free Software Foundation.

  This library is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
  General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this library; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
#include <glib.h>
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include "imengines-wp.h"
imengines_wp_plugin *wp;
void *wp_handle;
int imengines_wp_get_number_supported_languages(void)
{
  g_return_val_if_fail(wp != NULL,1);
  g_return_val_if_fail(wp->get_number_supported_languages != NULL,1);
  return wp->get_number_supported_languages();
}
imengines_im_status imengines_wp_save_dictionary(unsigned int dictionary)
{
  g_return_val_if_fail(wp != NULL,IM_STATUS_FAILED);
  g_return_val_if_fail(wp->save_dictionary != NULL,IM_STATUS_FAILED);
  return wp->save_dictionary(dictionary);
}
imengines_im_status imengines_wp_add_word(const char *word, unsigned int dictionary, unsigned int language_index)
{
  g_return_val_if_fail(wp != NULL,IM_STATUS_FAILED);
  g_return_val_if_fail(wp->add_word != NULL,IM_STATUS_FAILED);
  return wp->add_word(word, dictionary, language_index);
}
imengines_im_status imengines_wp_delete_word(const char *word, unsigned int dictionary, unsigned int language_index)
{
  g_return_val_if_fail(wp != NULL,IM_STATUS_FAILED);
  g_return_val_if_fail(wp->delete_word != NULL,IM_STATUS_FAILED);
  return wp->delete_word(word, dictionary, language_index);
}
imengines_im_status imengines_wp_hit_word(const char *word, unsigned int dictionary, unsigned int language_index)
{
  g_return_val_if_fail(wp != NULL,IM_STATUS_FAILED);
  g_return_val_if_fail(wp->hit_word != NULL,IM_STATUS_FAILED);
  return wp->hit_word(word, dictionary, language_index);
}
gboolean imengines_wp_word_exists(const char *word, unsigned int dictionary, gboolean *exists)
{
  g_return_val_if_fail(wp != NULL,FALSE);
  g_return_val_if_fail(wp->word_exists != NULL,FALSE);
  return wp->word_exists(word, dictionary, exists);
}
imengines_im_status imengines_wp_get_max_candidates(int *number)
{
  g_return_val_if_fail(wp != NULL,IM_STATUS_FAILED);
  g_return_val_if_fail(wp->get_max_candidates != NULL,IM_STATUS_FAILED);
  return wp->get_max_candidates(number);
}
imengines_im_status imengines_wp_set_max_candidates(int max_candidates)
{
  g_return_val_if_fail(wp != NULL,IM_STATUS_FAILED);
  g_return_val_if_fail(wp->set_max_candidates != NULL,IM_STATUS_FAILED);
  return wp->set_max_candidates(max_candidates);
}
imengines_im_status imengines_wp_get_candidates(const gchar *previous_word, const gchar *current_word, imengines_wp_candidates *candidates)
{
  g_return_val_if_fail(wp != NULL,IM_STATUS_FAILED);
  g_return_val_if_fail(wp->get_candidates != NULL,IM_STATUS_FAILED);
  return wp->get_candidates(previous_word, current_word, candidates);
}
imengines_im_status imengines_wp_detach_dictionary(unsigned int dictionary)
{
  g_return_val_if_fail(wp != NULL,IM_STATUS_FAILED);
  g_return_val_if_fail(wp->detach_dictionary != NULL,IM_STATUS_FAILED);
  return wp->detach_dictionary(dictionary);
}
imengines_im_status imengines_wp_attach_dictionary(unsigned int dictionary, gboolean use_dictionary)
{
  g_return_val_if_fail(wp != NULL,IM_STATUS_FAILED);
  g_return_val_if_fail(wp->attach_dictionary != NULL,IM_STATUS_FAILED);
  return wp->attach_dictionary(dictionary, use_dictionary);
}
imengines_im_status imengines_wp_set_data(const char *d, const char *v)
{
  g_return_val_if_fail(wp != NULL,IM_STATUS_FAILED);
  g_return_val_if_fail(wp->set_data != NULL,IM_STATUS_FAILED);
  return wp->set_data(d, v);
}
imengines_im_status imengines_wp_set_prediction_language(const char *language, unsigned int language_index)
{
  g_return_val_if_fail(wp != NULL,IM_STATUS_FAILED);
  g_return_val_if_fail(wp->set_language != NULL,IM_STATUS_FAILED);
  return wp->set_language(language, language_index);
}
void imengines_wp_destroy(void)
{
  g_return_if_fail(wp != NULL);
  g_return_if_fail(wp->destroy != NULL);
  wp->destroy();
  wp = 0;
}
imengines_im_status imengines_wp_init(const char *wpengine)
{
  char str[1024];
  imengines_wp_plugin *(*func)();
  memset(str, 0, 1024);
  snprintf(str, 1023, "%s/libim_wp_plugin_%s.so", "/usr/lib/libimengines", wpengine);
  if (wp)
    imengines_wp_destroy();
  wp = 0;
  wp_handle = dlopen(str, 2);
  if (wp_handle)
  {
    func = (imengines_wp_plugin *(*)())dlsym(wp_handle, "imengines_wp_plugin_init");
    if (func)
    {
      wp = func();
      if (wp)
        return IM_STATUS_OK;
      g_log(0, G_LOG_LEVEL_WARNING, "Failed calling init function for WP");
    }
    else
    {
      g_log(0, G_LOG_LEVEL_WARNING, "Can't find init function in WP plugin %s", wpengine);
    }
  }
  else
  {
    g_log((const gchar *)IM_STATUS_OK, G_LOG_LEVEL_WARNING, "Can't open WP plugin library %s", str);
  }
  if (wp_handle)
    dlclose(wp_handle);
  return IM_STATUS_FAILED;
}
