from distutils.core import setup, Extension

module1 = Extension(
	'hashf', # название модуля внутри Python
	 sources = ['hashf.c, Hashf.h'] # Исходные файлы модуля
)

setup(
	name = 'hashf',              # название модуля (my_plus.__name__)
	version = '1.1',               # версия модуля
	description = 'hash module', # описание модуля
	ext_modules= [module1]         # объекты типа Extension (мы объявили его выше)
)
