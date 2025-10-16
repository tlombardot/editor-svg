#include "../config/struct.h"
#include "../components/get.h"
#include <stdio.h>
#include "../utils/windows_user.h"

// Tron neon colors
#define RESET       "\x1b[0m"
#define BOLD        "\x1b[1m"
#define DIM         "\x1b[2m"

#define RED         "\x1b[91m"
#define GREEN       "\x1b[92m"
#define YELLOW      "\x1b[93m"
#define BLUE        "\x1b[94m"
#define MAGENTA     "\x1b[95m"
#define CYAN        "\x1b[96m"
#define WHITE       "\x1b[97m"



// --- FILL STYLE ---
Style createFillStyle(Style *style) {
    slowPrint(BOLD MAGENTA "◆ FILL COLOR STYLE ◆\n" RESET, 2);
    HeaderLine();

    slowPrint(CYAN "Enter RGB values for fill color (0–200):\n" RESET, 1);

    slowPrint(YELLOW " Red   : " RESET, 1);
    style->RF = getInt();
    slowPrint(YELLOW " Green : " RESET, 1);
    style->GF = getInt();
    slowPrint(YELLOW " Blue  : " RESET, 1);
    style->BF = getInt();

    char msg[128];
    sprintf(msg, BOLD GREEN "✓ Fill color set: " RESET MAGENTA "RGB(%d, %d, %d)\n",
            style->RF, style->GF, style->BF);
    slowPrint(msg, 2);
    HeaderLine();
    return *style;
}

Style createStrokeStyle(Style *style) {
    slowPrint(BOLD MAGENTA "◆ STROKE COLOR STYLE ◆\n" RESET, 2);
    HeaderLine();

    slowPrint(CYAN "Enter RGB values for stroke color (0–200):\n" RESET, 1);

    slowPrint(YELLOW " Red   : " RESET, 1);
    style->RS = getInt();
    slowPrint(YELLOW " Green : " RESET, 1);
    style->GS = getInt();
    slowPrint(YELLOW " Blue  : " RESET, 1);
    style->BS = getInt();

    char msg[128];
    sprintf(msg, BOLD GREEN "✓ Stroke color set: " RESET MAGENTA "RGB(%d, %d, %d)\n",
            style->RS, style->GS, style->BS);
    slowPrint(msg, 2);
    HeaderLine();
    return *style;
}

Style createAngleStyle(Style *style) {
    slowPrint(BOLD MAGENTA "◆ ANGLE STYLE ◆\n" RESET, 2);
    HeaderLine();

    slowPrint(CYAN "Enter rotation angle (0–200): " RESET, 1);
    style->angle = getInt();

    char msg[128];
    sprintf(msg, BOLD GREEN "✓ Angle set to: " RESET MAGENTA "%d°\n", style->angle);
    slowPrint(msg, 2);
    HeaderLine();
    return *style;
}

Translate createTranslateStyle(Style *style) {
    Translate translate = style->translate;

    slowPrint(BOLD MAGENTA "◆ TRANSLATE STYLE ◆\n" RESET, 2);
    HeaderLine();

    slowPrint(YELLOW " X translation (0–200): " RESET, 1);
    translate.x = getInt();
    slowPrint(YELLOW " Y translation (0–200): " RESET, 1);
    translate.y = getInt();

    char msg[128];
    sprintf(msg, BOLD GREEN "✓ Translation set: " RESET MAGENTA "(%d, %d)\n", translate.x, translate.y);
    slowPrint(msg, 2);
    HeaderLine();

    style->translate = translate;
    return translate;
}
