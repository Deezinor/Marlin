#!/usr/bin/env bash
#
# findMissingTranslations.sh
#
# Locate all language strings needing an update based on English
#
# Usage: findMissingTranslations.sh [language codes]
#
# If no language codes are specified then all languages will be checked
#

langname() {
  case "$1" in
     an   ) echo "Aragonese" ;;            bg     ) echo "Bulgarian" ;;
     ca   ) echo "Catalan" ;;              cz     ) echo "Czech" ;;
     da   ) echo "Danish" ;;               de     ) echo "German" ;;
     el   ) echo "Greek" ;;                el_CY  ) echo "Greek (Cyprus)" ;;
     el_gr) echo "Greek (Greece)" ;;       en     ) echo "English" ;;
     es   ) echo "Spanish" ;;              eu     ) echo "Basque-Euskera" ;;
     fi   ) echo "Finnish" ;;              fr     ) echo "French" ;;
     fr_na) echo "French (no accent)" ;;   gl     ) echo "Galician" ;;
     hr   ) echo "Croatian (Hrvatski)" ;;  hu     ) echo "Hungarian / Magyar" ;;
     it   ) echo "Italian" ;;              jp_kana) echo "Japanese (Kana)" ;;
     ko_KR) echo "Korean" ;;               nl     ) echo "Dutch" ;;
     pl   ) echo "Polish" ;;               pt     ) echo "Portuguese" ;;
     pt_br) echo "Portuguese (Brazil)" ;;  ro     ) echo "Romanian" ;;
     ru   ) echo "Russian" ;;              sk     ) echo "Slovak" ;;
     sv   ) echo "Swedish" ;;              tr     ) echo "Turkish" ;;
     uk   ) echo "Ukrainian" ;;            vi     ) echo "Vietnamese" ;;
     zh_CN) echo "Simplified Chinese" ;;   zh_TW  ) echo "Traditional Chinese" ;;
     *    ) echo "<unknown>" ;;
  esac
}

LANGHOME="Marlin/src/lcd/language"

[ -d $LANGHOME ] && cd $LANGHOME

FILES=$(ls language_*.h | grep -v -E "(_en|_test)\.h" | sed -E 's/language_([^\.]+)\.h/\1/' | tr '\n' ' ')

# Get files matching the given arguments
TEST_LANGS=""
if [[ -n $@ ]]; then
  for K in "$@"; do
    for F in $FILES; do
      [[ "$F" != "${F%$K*}" ]] && TEST_LANGS+="$F "
    done
  done
  [[ -z $TEST_LANGS ]] && { echo "No languages matching $@." ; exit 0 ; }
else
  TEST_LANGS=$FILES
fi

echo "Missing strings for $TEST_LANGS..."

for WORD in $(awk '/LSTR/{print $2}' language_en.h); do
  [[ $WORD == "MSG_MARLIN" ]] && break
  LANG_LIST=""
  for LANG in $TEST_LANGS; do
    if [[ $(grep -c -E "^ *LSTR +$WORD\b" language_${LANG}.h) -eq 0 ]]; then
      INHERIT=$(awk '/using namespace/{print $3}' language_${LANG}.h | sed -E 's/Language_([a-zA-Z_]+)\s*;/\1/')
      if [[ -z $INHERIT || $INHERIT == "en" ]]; then
        LANG_LIST+=" $LANG"
      elif [[ $(grep -c -E "^ *LSTR +$WORD\b" language_${INHERIT}.h) -eq 0 ]]; then
        LANG_LIST+=" $LANG"
      fi
    fi
  done
  [[ -n $LANG_LIST ]] && printf "%-38s :%s\n" "$WORD" "$LANG_LIST"
done
