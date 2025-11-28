import ctypes

lib = ctypes.CDLL("./libstr.so")       # or strlib.dll on Windows
lib.reverse_string.restype = ctypes.c_char_p
lib.reverse_string.argtypes = [ctypes.c_char_p]

result = lib.reverse_string(b"Joel Gautam")
print(result.decode())
