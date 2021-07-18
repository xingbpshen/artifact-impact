from PyInstaller.utils.hooks import collect_all


def hook(hook_api):
    packages = [
        'tensorflow',
        #'tensorflow_core',
        'astor',
	'keras'
	#'scipy.special.cython_special',
	#'scipy.spatial.transform._rotation_groups'
    ]
    for package in packages:
        datas, binaries, hiddenimports = collect_all(package)
        hook_api.add_datas(datas)
        hook_api.add_binaries(binaries)
        hook_api.add_imports(*hiddenimports)