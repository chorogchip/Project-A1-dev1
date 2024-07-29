{ pkgs }: with pkgs; let SDL = [
  SDL2.dev
  SDL2_image
  SDL2_ttf
  SDL2_net
  SDL2_gfx
  SDL2_sound
  SDL2_mixer
]; in
{
  deps = [
    clang_16
    ccls
    gdb
    gnumake
    rnix-lsp
    taplo
  ] ++ SDL;
  env = {
    CPLUS_INCLUDE_PATH = lib.makeSearchPath "include/SDL2" SDL;
  };
}
