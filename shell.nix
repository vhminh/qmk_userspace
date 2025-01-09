{ pkgs ? import <nixpkgs> {} }:
  pkgs.mkShell {
    nativeBuildInputs = with pkgs.buildPackages; [
      qmk
      bear
      clang-tools
      dfu-programmer
      usbutils
  ];
}
