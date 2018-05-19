#include <string.h>

static const struct
{
  char locale[6];
}
locales[]=
{
  { "af_ZA" },
  { "am_ET" },
  { "ar_AE" },
  { "ar_BH" },
  { "ar_DZ" },
  { "ar_EG" },
  { "ar_IN" },
  { "ar_IQ" },
  { "ar_JO" },
  { "ar_KW" },
  { "ar_LB" },
  { "ar_LY" },
  { "ar_MA" },
  { "ar_OM" },
  { "ar_QA" },
  { "ar_SA" },
  { "ar_SD" },
  { "ar_SY" },
  { "ar_TN" },
  { "ar_YE" },
  { "az_AZ" },
  { "be_BY" },
  { "bg_BG" },
  { "bn_IN" },
  { "br_FR" },
  { "bs_BA" },
  { "ca_ES" },
  { "cs_CZ" },
  { "cy_GB" },
  { "da_DK" },
  { "de_AT" },
  { "de_BE" },
  { "de_CH" },
  { "de_DE" },
  { "de_LU" },
  { "el_GR" },
  { "en_AU" },
  { "en_BW" },
  { "en_CA" },
  { "en_DK" },
  { "en_GB" },
  { "en_HK" },
  { "en_IE" },
  { "en_IN" },
  { "en_NZ" },
  { "en_PH" },
  { "en_SG" },
  { "en_US" },
  { "en_ZA" },
  { "en_ZW" },
  { "eo_EO" },
  { "es_AR" },
  { "es_BO" },
  { "es_CL" },
  { "es_CO" },
  { "es_CR" },
  { "es_DO" },
  { "es_EC" },
  { "es_ES" },
  { "es_GT" },
  { "es_HN" },
  { "es_MX" },
  { "es_NI" },
  { "es_PA" },
  { "es_PE" },
  { "es_PR" },
  { "es_PY" },
  { "es_SV" },
  { "es_US" },
  { "es_UY" },
  { "es_VE" },
  { "et_EE" },
  { "eu_ES" },
  { "fa_IR" },
  { "fi_FI" },
  { "fo_FO" },
  { "fr_BE" },
  { "fr_CA" },
  { "fr_CH" },
  { "fr_FR" },
  { "fr_LU" },
  { "ga_IE" },
  { "gd_GB" },
  { "gl_ES" },
  { "gv_GB" },
  { "he_IL" },
  { "hi_IN" },
  { "hr_HR" },
  { "hu_HU" },
  { "hy_AM" },
  { "id_ID" },
  { "is_IS" },
  { "it_CH" },
  { "it_IT" },
  { "iw_IL" },
  { "ja_JP" },
  { "ka_GE" },
  { "kl_GL" },
  { "ko_KR" },
  { "kw_GB" },
  { "lt_LT" },
  { "lv_LV" },
  { "mi_NZ" },
  { "mk_MK" },
  { "mr_IN" },
  { "ms_MY" },
  { "mt_MT" },
  { "nl_BE" },
  { "nl_NL" },
  { "nn_NO" },
  { "no_NO" },
  { "oc_FR" },
  { "pl_PL" },
  { "pt_BR" },
  { "pt_PT" },
  { "ro_RO" },
  { "ru_RU" },
  { "ru_UA" },
  { "se_NO" },
  { "sk_SK" },
  { "sl_SI" },
  { "sq_AL" },
  { "sr_YU" },
  { "sv_FI" },
  { "sv_SE" },
  { "ta_IN" },
  { "te_IN" },
  { "tg_TJ" },
  { "th_TH" },
  { "ti_ER" },
  { "ti_ET" },
  { "tl_PH" },
  { "tr_TR" },
  { "tt_RU" },
  { "uk_UA" },
  { "ur_PK" },
  { "uz_UZ" },
  { "vi_VN" },
  { "wa_BE" },
  { "yi_US" },
  { "zh_CN" },
  { "zh_HK" },
  { "zh_SG" },
  { "zh_TW" }
};

#define NUM_LOCALES (sizeof(locales) / sizeof(locales[0]))

const char *
imengines_locale_to_string(int locale)
{
  if (locale < NUM_LOCALES)
    return locales[locale].locale;

  return NULL;
}

int
imengines_string_to_locale(const char *s)
{
  int i;

  if (!s)
    return -1;

  for (i = 0; i < NUM_LOCALES; i++)
  {
    if (!strncmp(locales[i].locale, s, sizeof(locales[0]) - 1))
      return i;
  }

  return -1;
}
