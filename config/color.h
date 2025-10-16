
#ifndef COLORS_H
#define COLORS_H

/* Reset – revient aux attributs par défaut du terminal */
#define RESET          "\033[0m"

/* ---------------------------  FOREGROUND  --------------------------- */

/* Couleurs primaires (adoucies) */
#define RED            "\033[38;2;230;60;60m"
#define GREEN          "\033[38;2;0;200;100m"
#define BLUE           "\033[38;2;50;120;255m"      // Bleu acier : lisible et élégant

/* Nuances secondaires (désaturées pour plus de confort) */
#define YELLOW         "\033[38;2;255;220;70m"
#define CYAN           "\033[38;2;80;220;255m"      // Bleu-ciel doux
#define MAGENTA        "\033[38;2;220;80;220m"

/* Blanc & noir */
#define WHITE          "\033[38;2;230;230;230m"
#define BLACK          "\033[38;2;0;0;0m"

/* Nuances supplémentaires */
#define ORANGE         "\033[38;2;255;165;60m"      // Orange clair, moins agressif
#define PURPLE         "\033[38;2;140;90;255m"
#define BROWN          "\033[38;2;150;90;40m"
#define GRAY           "\033[38;2;140;140;140m"
#define LIGHTGRAY      "\033[38;2;200;200;200m"
#define DARK_RED       "\033[38;2;150;0;0m"
#define DARK_GREEN     "\033[38;2;0;120;60m"
#define DARK_BLUE      "\033[38;2;20;60;160m"
#define PINK           "\033[38;2;255;140;180m"
#define TEAL           "\033[38;2;0;160;160m"
#define OLIVE          "\033[38;2;160;160;40m"
#define NAVY           "\033[38;2;40;70;160m"
#define GOLD           "\033[38;2;255;215;100m"
#define SILVER         "\033[38;2;192;192;192m"
#define MAROON         "\033[38;2;120;0;0m"
#define LIME           "\033[38;2;180;255;100m"
#define INDIGO         "\033[38;2;75;90;180m"


/* ---------------------------  BACKGROUND  --------------------------- */

#define BG_RED         "\033[48;2;254;0;0m"
#define BG_GREEN       "\033[48;2;0;254;0m"
#define BG_BLUE        "\033[48;2;0;0;254m"
#define BG_YELLOW      "\033[48;2;254;254;0m"
#define BG_CYAN        "\033[48;2;0;254;254m"
#define BG_MAGENTA     "\033[48;2;254;0;254m"
#define BG_WHITE       "\033[48;2;254;254;254m"
#define BG_BLACK       "\033[48;2;0;0;0m"
#define BG_ORANGE      "\033[48;2;254;127;0m"
#define BG_PURPLE      "\033[48;2;127;0;254m"
#define BG_BROWN       "\033[48;2;139;69;19m"
#define BG_GRAY        "\033[48;2;128;128;128m"
#define BG_LIGHT_GRAY  "\033[48;2;200;200;200m"
#define BG_DARK_RED    "\033[48;2;139;0;0m"
#define BG_DARK_GREEN  "\033[48;2;0;100;0m"
#define BG_DARK_BLUE   "\033[48;2;0;0;139m"
#define BG_PINK        "\033[48;2;254;105;180m"
#define BG_TEAL        "\033[48;2;0;128;128m"
#define BG_OLIVE       "\033[48;2;128;128;0m"
#define BG_NAVY        "\033[48;2;0;0;128m"
#define BG_GOLD        "\033[48;2;254;215;0m"
#define BG_SILVER      "\033[48;2;192;192;192m"
#define BG_MAROON      "\033[48;2;128;0;0m"
#define BG_LIME        "\033[48;2;191;254;0m"
#define BG_INDIGO      "\033[48;2;75;0;130m"

#define BOLD           "\033[1m"
#define DIM            "\033[2m"
#define ITALIC         "\033[3m"
#define UNDERLINE      "\033[4m"
#define BLINK_SLOW     "\033[5m"
#define REVERSE        "\033[7m"
#define HIDDEN         "\033[8m"
#define STRIKETHROUGH  "\033[9m"

#endif
