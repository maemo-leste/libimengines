/**
  @file imengines-wp.h

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

typedef struct _imengines_wp_candidates {
  int number_of_candidates;
  char candidate[10][128];
} imengines_wp_candidates;

typedef enum _imengines_im_status {
  IM_STATUS_UNKNOWN = -1,
  IM_STATUS_OK = 0,
  IM_STATUS_FAILED,
  IM_STATUS_OUT_OF_RANGE,
  IM_STATUS_NOT_ENOUGHT_MEMORY,
  IM_STATUS_OUT_OF_LIMITS,
  IM_STATUS_OUT_OF_DISKSPACE,
  IM_STATUS_NOT_SUPPORTED
} imengines_im_status;
typedef struct _imengines_wp_plugin {
  void (*destroy)(void);
  imengines_im_status (*set_language)(const char *language, unsigned int language_index);
  imengines_im_status (*set_data)(const char *d, const char *v);
  imengines_im_status (*attach_dictionary)(unsigned int dictionary, gboolean use_dictionary);
  imengines_im_status (*detach_dictionary)(unsigned int dictionary);
  imengines_im_status (*get_candidates)(const gchar *previous_word, const gchar *current_word, imengines_wp_candidates *candidates);
  imengines_im_status (*set_max_candidates)(int max_candidates);
  imengines_im_status (*get_max_candidates)(int *number);
  gboolean (*word_exists)(const char *word, unsigned int dictionary, unsigned int *language_index);
  imengines_im_status (*hit_word)(const char *word, unsigned int dictionary, unsigned int language_index);
  imengines_im_status (*delete_word)(const char *word, unsigned int dictionary, unsigned int language_index);
  imengines_im_status (*add_word)(const char *word, unsigned int dictionary, unsigned int language_index);
  imengines_im_status (*save_dictionary)(unsigned int dictionary);
  int (*get_number_supported_languages)(void);
} imengines_wp_plugin;
int imengines_wp_get_number_supported_languages(void);
imengines_im_status imengines_wp_save_dictionary(unsigned int dictionary);
imengines_im_status imengines_wp_add_word(const char *word, unsigned int dictionary, unsigned int language_index);
imengines_im_status imengines_wp_delete_word(const char *word, unsigned int dictionary, unsigned int language_index);
imengines_im_status imengines_wp_hit_word(const char *word, unsigned int dictionary, unsigned int language_index);
gboolean imengines_wp_word_exists(const char *word, unsigned int dictionary, unsigned int *language_index);
imengines_im_status imengines_wp_get_max_candidates(int *number);
imengines_im_status imengines_wp_set_max_candidates(int max_candidates);
imengines_im_status imengines_wp_get_candidates(const gchar *previous_word, const gchar *current_word, imengines_wp_candidates *candidates);
imengines_im_status imengines_wp_detach_dictionary(unsigned int dictionary);
imengines_im_status imengines_wp_attach_dictionary(unsigned int dictionary, gboolean use_dictionary);
imengines_im_status imengines_wp_set_data(const char *d, const char *v);
imengines_im_status imengines_wp_set_prediction_language(const char *language, unsigned int language_index);
void imengines_wp_destroy(void);
imengines_im_status imengines_wp_init(const char *wpengine);
