
#include "../config/struct.h"
#include "../components/get.h"
#include <stdio.h>

Style createFillStyle(Style *style) {
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║           🎨 FILL COLOR STYLE          ║\n");
    printf("╠════════════════════════════════════════╣\n");
    printf("║  Enter RGB values for the FILL color:  ║\n");
    printf("╚════════════════════════════════════════╝\n");

    printf("🔴  Red (0–200): ➤ ");
    style->RF = getInt();

    printf("🟢  Green (0–200): ➤ ");
    style->GF = getInt();

    printf("🔵  Blue (0–200): ➤ ");
    style->BF = getInt();

    printf("\n✅ Fill color successfully set to RGB(%d, %d, %d)\n",
           style->RF, style->GF, style->BF);
    return *style;
}

Style createStrokeStyle(Style *style) {
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║          ✏️  STROKE COLOR STYLE         ║\n");
    printf("╠════════════════════════════════════════╣\n");
    printf("║  Enter RGB values for the STROKE color:║\n");
    printf("╚════════════════════════════════════════╝\n");

    printf("🔴  Red (0–200): ➤ ");
    style->RS = getInt();

    printf("🟢  Green (0–200): ➤ ");
    style->GS = getInt();

    printf("🔵  Blue (0–200): ➤ ");
    style->BS = getInt();

    printf("\n✅ Stroke color successfully set to RGB(%d, %d, %d)\n",
           style->RS, style->GS, style->BS);
    return *style;
}

Style createAngleStyle(Style *style) {
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║             🌀 ANGLE STYLE             ║\n");
    printf("╠════════════════════════════════════════╣\n");
    printf("║  Define the rotation angle of shape    ║\n");
    printf("╚════════════════════════════════════════╝\n");

    printf("↩️  Enter angle (0–200): ➤ ");
    style->angle = getInt();

    printf("\n✅ Angle successfully set to %d°\n", style->angle);
    return *style;
}

Translate createTranslateStyle(Style *style) {
    Translate translate = style->translate;
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║             🚀 TRANSLATE STYLE         ║\n");
    printf("╠════════════════════════════════════════╣\n");
    printf("║  Define the translation of shape       ║\n");
    printf("╚════════════════════════════════════════╝\n");

    printf("↩️  Enter x translation (0–200): ➤ ");
    translate.x = getInt();

    printf("↩️  Enter y translation (0–200): ➤ ");
    translate.y = getInt();

    printf("\n✅ Translation successfully set to (%d, %d)\n", translate.x, translate.y);
    style->translate = translate;
    return translate;
}
