# My fork of ZSA's fork of QMK Firmware

[![Current Version](https://img.shields.io/github/tag/ErgoDox-EZ/qmk_firmware.svg)](https://github.com/ErgoDox-EZ/qmk_firmware/tags)
[![Build Status](https://travis-ci.org/ErgoDox-EZ/qmk_firmware.svg?branch=master)](https://travis-ci.org/ErgoDox-EZ/qmk_firmware)
[![GitHub contributors](https://img.shields.io/github/contributors/ErgoDox-EZ/qmk_firmware.svg)](https://github.com/ErgoDox-EZ/qmk_firmware/pulse/monthly)
[![GitHub forks](https://img.shields.io/github/forks/ErgoDox-EZ/qmk_firmware.svg?style=social&label=Fork)](https://github.com/ErgoDox-EZ/qmk_firmware/)

This purpose of my fork of [ZSA's fork](https://github.com/zsa/qmk_firmware) is maintain a clean repo that only contains the keyboard code that I need, and as little else as possible.  This is to keep it lightweight, since I currently only own one QMK-supported keyboard: the ZSA Moonlander.

## Supported Keyboards

* [Moonlander Mark I](/keyboards/moonlander)

## Maintainers

QMK is developed and maintained by Jack Humbert of OLKB with contributions from the community, and of course, [Hasu](https://github.com/tmk). The ZSA branch is maintained by Drashna, ZSA's official QMK Liaison, and by Florian Didron, ZSA's lead developer, with input from Erez Zukerman (ZSA CEO). And my fork is maintained by me, Daniel.

# Update Process

1. Check out branch from my default branch, `main` (which diverges from the ZSA upstream, which updates their default branch to match the latest firmware release):
    1. `git remote add dabrady https://github.com/dabrady/qmk_firmware.git`
    2. `git fetch --all`
    3. `git checkout -B branchname dabrady/main`
    4. `git push -u origin branchname`
2. Check for upstream changes in ZSA's fork; I want to be as up to date with them as possible, without being bloated by keyboards and keymaps I don't use.
3. `git cherry-pick` the commits we want
    - `git rm docs/* -r` to remove the document updates when cherry picking. Repeat for any keyboard/keymap/etc that have changes that we aren't interested in
4. Commit update
5. Open pull request, and include information about the commit

## Strategy

To keep PRs small and easier to test, they should ideally be 1:1 with commits from ZSA's fork of QMK Firmware. They should only group commits if/when it makes sense. Such as multiple commits for a specific feature (split RGB support, for instance)

## Merging

Pull Requests should be merged/rebased, not squashed, so we can maintain a commit history that is close to ZSA's fork of QMK Firmware, for ease of reference.
