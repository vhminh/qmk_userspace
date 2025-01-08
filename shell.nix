{ pkgs ? import <nixpkgs> {} }:
  pkgs.mkShell {
    nativeBuildInputs = with pkgs.buildPackages; [
      qmk
      bear
      clangd
      dfu-programmer
      usbutils
  ];
}
