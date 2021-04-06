## 1. Homebrew로 Opencv, DLib 설치

터미널에서 Homebrew가 없다면 설치 먼저

``` 
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
```

터미널에서 최신 버전의 Opencv를 설치

```
brew update
brew install opencv
brew upgrade opencv
```

혹시 몰라서

```
See: https://docs.brew.sh/Homebrew-and-Python

python@3.8 is keg-only, which means it was not symlinked into /usr/local,
because this is an alternate version of another formula.

If you need to have python@3.8 first in your PATH, run:
  echo 'export PATH="/usr/local/opt/python@3.8/bin:$PATH"' >> ~/.zshrc

For compilers to find python@3.8 you may need to set:
  export LDFLAGS="-L/usr/local/opt/python@3.8/lib"

For pkg-config to find python@3.8 you may need to set:
  export PKG_CONFIG_PATH="/usr/local/opt/python@3.8/lib/pkgconfig"

==> emacs
To have launchd start emacs now and restart at login:
  brew services start emacs
Or, if you don't want/need a background service you can just run:
  emacs
==> cask
Emacs Lisp files have been installed to:
  /usr/local/share/emacs/site-lisp/cask
```

### 결과

시키는 대로 깔았는데, import가 안된다 ( ꈨຶ ˙̫̮ ꈨຶ ) 

---

## 2. pip install

추가로 `numpy`, `pandas`도

```
pip install numpy
pip install opencv-python
```

또 추가로 `dlib` install 하려는데 에러남;;

![image](https://user-images.githubusercontent.com/47033052/113672264-72f76500-96f2-11eb-9ecb-730643e7d1cd.png)

보아하니 Camake 설치해야 가능한거 같다.

- homebrew로 `cmake` 설치 후 다시 `dlib` 설치

```
brew install cmake
python3 -m pip install dlib
```



제대로 설치되었고, import도 잘됨 >< 꺄룰

<img src="https://user-images.githubusercontent.com/47033052/113673232-b0a8bd80-96f3-11eb-83d1-7c8194baa87d.png" alt="image" style="zoom:50%;" />

