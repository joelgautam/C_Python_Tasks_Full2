from setuptools import setup, Extension

ext = Extension("array_module", sources=["arraylib.c"])

setup(
    name="array_module",
    version="1.0",
    ext_modules=[ext]
)
