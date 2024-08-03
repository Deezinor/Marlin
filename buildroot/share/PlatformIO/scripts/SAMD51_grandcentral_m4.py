#
# SAMD51_grandcentral_m4.py
# Customizations for env:SAMD51_grandcentral_m4
#
import pioutil
if pioutil.is_pio_build():
    from os.path import join, isfile
    import shutil
<<<<<<< HEAD
    env = pioutil.env

    mf = env["MARLIN_FEATURES"]
    rxBuf = mf["RX_BUFFER_SIZE"] if "RX_BUFFER_SIZE" in mf else "0"
    txBuf = mf["TX_BUFFER_SIZE"] if "TX_BUFFER_SIZE" in mf else "0"

    serialBuf = str(max(int(rxBuf), int(txBuf), 350))

=======

    Import("env")

    mf = env["MARLIN_FEATURES"]
    rxBuf = mf["RX_BUFFER_SIZE"] if "RX_BUFFER_SIZE" in mf else "0"
    txBuf = mf["TX_BUFFER_SIZE"] if "TX_BUFFER_SIZE" in mf else "0"

    serialBuf = str(max(int(rxBuf), int(txBuf), 350))

>>>>>>> upstream/bugfix-2.0.x
    build_flags = env.get('BUILD_FLAGS')
    build_flags.append("-DSERIAL_BUFFER_SIZE=" + serialBuf)
    env.Replace(BUILD_FLAGS=build_flags)
