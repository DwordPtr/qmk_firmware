# ErgoVim

A querty-like layout designed to make vim and tmux usage easier.
Based on [rask](https://github.com/qmk/qmk_firmware/blob/ee700b2e831067bdb7584425569b61bc6329247b/keyboards/ergodox_infinity/keymaps/rask/README.md)

## Features
 - Macros for fast TMUX, and VIM usage.
 - Opinionated mappings based on rask

## Whats bad
- assumes `\` is vim leader and that you use NERDCommenter
- that `<C-b>` is your tmux prefix
- that you share opinions of the author


## Building and flashing

Follow the main Infinity ErgoDox guide but use the following layout:

    $ sudo make ergodox_ez:rask

Eventually this will be:

    $ sudo make ergodox_ez:ergovim
