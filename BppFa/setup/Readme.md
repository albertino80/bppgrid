
### How to upgrade Font Awesome:

Open https://fontawesome.com/

Download latest FontAwesome icons (follow **Download Font Awesome Free for the Web**)

Extract:
- webfonts/fa-brands-400.ttf
- webfonts/fa-regular-400.ttf
- webfonts/fa-solid-900.ttf
- metada/icons.json

Obtaining:
- BppFa/fonts/fa-brands-400.ttf
- BppFa/fonts/fa-regular-400.ttf
- BppFa/fonts/fa-solid-900.ttf
- BppFa/setup/icons.json

With FontForge (https://fontforge.org/en-US/)

Edit Font `BppFa/fonts/fa-regular-400.ttf` Modify the property: Informations->TTF Names->WWS Family: `Font Awesome 5 Free Regular`

Edit Font `BppFa/fonts/fa-solid-900.ttf` Modify the property: Informations->TTF Names->WWS Family: `Font Awesome 5 Free Solid`

Execute (CLI):
```
cd BppFa/setup
python extractfa.py icons.json
```

open `fa_class.h`, copy content and paste in `BppFa/bppfontawesome.h`