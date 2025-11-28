from setuptools import setup, Extension
import pybind11

ext = Extension(
    "concat_module",
    sources=["concat.cpp"],
    include_dirs=[pybind11.get_include()]
)

setup(
    name="concat_module",
    version="1.0",
    ext_modules=[ext]
)
