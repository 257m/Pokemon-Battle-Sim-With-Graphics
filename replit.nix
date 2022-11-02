{ pkgs }: {
	deps = [
		pkgs.cloc
  pkgs.htop
  pkgs.vim
  pkgs.zip
  pkgs.valgrind
  pkgs.pkgconfig
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
		pkgs.SDL2
		pkgs.SDL2_image
		pkgs.SDL2_ttf
	];
}