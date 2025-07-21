# Onegai Monsters

A repository exploring a decompilation of Onegai Monsters.

This is super minimal and likely won't become a full decomp project. I just wanted to see what was in this game mostly.

Grab tools

```sh
git submodule update --init --recursive
```

Install Dependencies
```sh
sudo apt install build-essential pkg-config git python3 wget python3-pip binutils-mips-linux-gnu python3-venv
```

Drop the baserom into the root of the project named `onegaimonsters.z64`

```sh
make setup
make extract
make
```

