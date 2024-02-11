# 2048 o'yinining terminal versiyasi | 2048 game in terminal

Kompilyatsiya qilish uchun kerak bo'ladigan kutubxonalarni o'rnatish | Installing dependencies:

```bash
    sudo apt install libncurses-dev pkg-config
```

Kompilyatisiya qilish | Compiling:

```bash
    g++ -o 2048 game.cpp class.cpp `pkg-config --cflags --libs ncurses`
```
