from setuptools import setup, Extension

module = Extension("square_module", sources=["square.c"])

setup(
    name="square_module",
    version="1.0",
    ext_modules=[module]
)
