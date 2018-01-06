MEMORY
{
    bl (rx) :             ORIGIN = 0x08000000,            LENGTH = 32K
    app (rx) :            ORIGIN = 0x08000000+32K,        LENGTH = 2M-32K-256K
    param1 (rx) :         ORIGIN = 0x08000000+2M-256K,    LENGTH = 128K
    param2 (rx) :         ORIGIN = 0x08000000+2M-128K,    LENGTH = 128K
    ram (rwx) :           ORIGIN = 0x20000000,            LENGTH = 192K-256
    app_bl_shared (rwx) : ORIGIN = 0x20000000+(192K-256), LENGTH = 256
}
