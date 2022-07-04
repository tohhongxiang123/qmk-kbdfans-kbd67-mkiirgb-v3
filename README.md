# Compile

```bash
qmk compile -kb kbdfans/kbd67/mkiirgb/v3 -km tohhongxiang
```

# Flash

1. Disconnect keyboard from the computer, hold escape while plugging the keyboard in to enter bootloader mode
    - If flashed before with this keymap, you can hold `fn` + `\` to enter bootloader mode
2. Open QMK Toolbox. Ensure that there is a message that shows the keyboard is connected: "LUFA MS device connected (USBSTOR): Compatible USB storage device USB Mass Storage Device (03EB:2045:0001) [F:]"
3. Select the correct `.bin` file to flash by clicking "Open" and choosing from the Windows Explorer
4. Click "Flash"
5. Once done with flashing, disconnect and reconnect the keyboard

# Features

1. Layers: Base (windows) layer, mac, function keys, numpad
2. Press `Fn` + `Alt` to toggle between Mac and Windows layer. Mac causes `alt` == `cmd` and `win` == `option`
3. Holding `Fn` activates the function layer (Pressing `fn` + `1` is `f1`)
4. `Esc` key normally, but `` ` `` key when `fn` is pressed

# Resources

- https://docs.qmk.fm/#/
- https://www.reddit.com/r/olkb/comments/a0texz/whatre_your_favorite_qmk_hacks/
- https://www.keebtalk.com/t/qmk-tap-dancing-and-one-shot-layers-quick-demo/4970