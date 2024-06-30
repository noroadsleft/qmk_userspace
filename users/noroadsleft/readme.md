# @noroadsleft's Userspace

This directory holds the code that's the same for every keyboard I use in QMK, which is currently:

- `kc60`
- `kbdfans/kbd75/rev1`
- `coseyfannitutti/discipline`


## Macro Features and Custom Keycodes

### [VRSN](./noroadsleft.c#L41-L45)

Outputs a string that tells me the Git commit from which my flashed firmware was built. Looks something like:

    coseyfannitutti/discipline:noroadsleft # @ 0.25.9-17-g3ffe8d

### Git Macros

Some frequently used Git commands.

| Keycode                             | Output                                                | Output with <kbd>Shift</kbd>                          |
| :---------------------------------- | :---------------------------------------------------- | :---------------------------------------------------- |
| [`G_PUSH`](./noroadsleft.c#L46-L50) | `git push origin `                                    | `git push origin `                                    |
| [`G_FTCH`](./noroadsleft.c#L51-L60) | `git fetch upstream `                                 | `git pull upstream `                                  |
| [`G_BRCH`](./noroadsleft.c#L61-L70) | `master`                                              | `$(git branch-name)`                                  |
| [`G_PWD`](./noroadsleft.c#L71-L84)  | `$( pwd \| sed -e 's;^.*/keyboards/;;' -e 's;/;_;g')` | `$( pwd \| sed -e 's;^.*/keyboards/;;' -e 's;/;_;g')` |

`$(git branch-name)` is an alias for `git rev-parse --abbrev-ref HEAD`, which normally returns the name of the current branch.

The `G_PWD` macro outputs a shell expansion that returns the current working directory in relation to `qmk_firmware/keyboards/`, and with the slashes replaced with underscores. I do a lot of keyboard refactoring in QMK, and this is a string I use regularly.

### Customized Keycodes

I used to have a boolean variable that changed the functionality of these keycodes, but I no longer work in the environment that I wrote the functionality for, so I took it out. The keycodes still exist because all my `keymap.c` files reference the custom keycodes I defined.

| Keycode                                | Action    |
| :------------------------------------- | :-------- |
| [`M_SALL`](./noroadsleft.c#L110-L114)  | `Ctrl+A`  |
| [`M_UNDO`](./noroadsleft.c#L115-L123)  | `Ctrl+Z`  |
| [`M_CUT`](./noroadsleft.c#L124-L128)   | `Ctrl+X`  |
| [`M_COPY`](./noroadsleft.c#L129-L133)  | `Ctrl+C`  |
| [`M_PASTE`](./noroadsleft.c#L134-L142) | `Ctrl+V`  |

### [Emulated Non-US Backslash](./noroadsleft.c#L29-L39)

Sometimes I type in languages from countries that use ISO layout, but my keyboards are all ANSI layout, so I have one key fewer than necessary.

This macro simulates the Non-US Backslash key if I hold Right Alt and tap the key to the right of Left Shift.

Requires defining `ANSI_NUBS_ROW` and `ANSI_NUBS_COL` in `config.h` at the keymap level.[<sup>1</sup>](#footnotes)

### [Emulated Numeric Keypad](./noroadsleft.c#L143-L157)

If I hold the Right Alt key, the number row (`KC_1` through `KC_0`) will output numpad keycodes instead of number row keycodes, enabling quicker access to characters like ™ and °.

### [Emulated Extended Function Keys](./noroadsleft.c#L158-L172)

Similar to the emulated numpad, if I hold the Right Alt key with the Fn key, the function row (`KC_F1` through `KC_F12`) will output keycodes `KC_F13` throught `KC_F24`.


## License

Copyright 2020-2024 James Young (@noroadsleft)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.


## Footnotes

- 1: [^](#emulated-non-us-backslash) `ANSI_NUBS_ROW` and `ANSI_NUBS_COL` are in the following locations:
  - [KC60](../../keyboards/kc60/keymaps/noroadsleft/config.h#L35-L36)
  - [KBDfans KBD75 rev1](../../keyboards/kbdfans/kbd75/keymaps/noroadsleft/config.h#L21-L22)
  - [CoseyFannitutti Discipline](../../keyboards/coseyfannitutti/discipline/keymaps/noroadsleft/config.h#L19-L20)
