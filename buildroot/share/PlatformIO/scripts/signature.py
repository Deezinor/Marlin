<<<<<<< HEAD
#!/usr/bin/env python3
=======
>>>>>>> upstream/bugfix-2.0.x
#
# signature.py
#
import schema

import subprocess,re,json,hashlib
from datetime import datetime
from pathlib import Path

<<<<<<< HEAD
def enabled_defines(filepath):
    '''
    Return all enabled #define items from a given C header file in a dictionary.
    A "#define" in a multi-line comment could produce a false positive if it's not
    preceded by a non-space character (like * in a multi-line comment).

    Output:
    Each entry is a dictionary with a 'name' and a 'section' key. We end up with:
        { MOTHERBOARD: { name: "MOTHERBOARD", section: "hardware" }, ... }

    TODO: Drop the 'name' key as redundant. For now it's useful for debugging.

    This list is only used to filter config-defined options from those defined elsewhere.

    Because the option names are the keys, only the last occurrence is retained.
    This means the actual used value might not be reflected by this function.
    The Schema class does more complete parsing for a more accurate list of options.

    While the Schema class parses the configurations on its own, this script will
    get the preprocessor output and get the intersection of the enabled options from
    our crude scraping method and the actual compiler output.
    We end up with the actual configured state,
    better than what the config files say. You can then use the
    resulting config.ini to produce more exact configuration files.
    '''
    outdict = {}
    section = "user"
    spatt = re.compile(r".*@section +([-a-zA-Z0-9_\s]+)$") # must match @section ...

    f = open(filepath, encoding="utf8").read().split("\n")

    # Get the full contents of the file and remove all block comments.
    # This will avoid false positives from #defines in comments
    f = re.sub(r'/\*.*?\*/', '', '\n'.join(f), flags=re.DOTALL).split("\n")

    for line in f:
        sline = line.strip()
        m = re.match(spatt, sline) # @section ...
        if m: section = m.group(1).strip() ; continue
        if sline[:7] == "#define":
            # Extract the key here (we don't care about the value)
            kv = sline[8:].strip().split()
            outdict[kv[0]] = { 'name':kv[0], 'section': section }
    return outdict
=======
#
# Return all macro names in a header as an array, so we can take
# the intersection with the preprocessor output, giving a decent
# reflection of all enabled options that (probably) came from the
# configuration files. We end up with the actual configured state,
# better than what the config files say. You can then use the
# resulting config.ini to produce more exact configuration files.
#
def extract_defines(filepath):
    f = open(filepath, encoding="utf8").read().split("\n")
    a = []
    for line in f:
        sline = line.strip()
        if sline[:7] == "#define":
            # Extract the key here (we don't care about the value)
            kv = sline[8:].strip().split()
            a.append(kv[0])
    return a
>>>>>>> upstream/bugfix-2.0.x

# Compute the SHA256 hash of a file
def get_file_sha256sum(filepath):
    sha256_hash = hashlib.sha256()
    with open(filepath,"rb") as f:
        # Read and update hash string value in blocks of 4K
        for byte_block in iter(lambda: f.read(4096),b""):
            sha256_hash.update(byte_block)
    return sha256_hash.hexdigest()

#
# Compress a JSON file into a zip file
#
import zipfile
<<<<<<< HEAD
def compress_file(filepath, storedname, outpath):
    with zipfile.ZipFile(outpath, 'w', compression=zipfile.ZIP_BZIP2, compresslevel=9) as zipf:
        zipf.write(filepath, arcname=storedname, compress_type=zipfile.ZIP_BZIP2, compresslevel=9)

def compute_build_signature(env):
    '''
    Compute the build signature by extracting all configuration settings and
    building a unique reversible signature that can be included in the binary.
    The signature can be reversed to get a 1:1 equivalent configuration file.
    Used by common-dependencies.py after filtering build files by feature.
    '''
    if 'BUILD_SIGNATURE' in env: return
    env.Append(BUILD_SIGNATURE=1)

    build_path = Path(env['PROJECT_BUILD_DIR'], env['PIOENV'])
    marlin_json = build_path / 'marlin_config.json'
    marlin_zip = build_path / 'mc.zip'

    # Definitions from these files will be kept
    header_paths = [ 'Marlin/Configuration.h', 'Marlin/Configuration_adv.h' ]

    # Check if we can skip processing
    hashes = ''
    for header in header_paths:
        hashes += get_file_sha256sum(header)[0:10]

    # Read a previously exported JSON file
    # Same configuration, skip recomputing the build signature
    same_hash = False
    try:
        with marlin_json.open() as infile:
            conf = json.load(infile)
            same_hash = conf['__INITIAL_HASH'] == hashes
            if same_hash:
                compress_file(marlin_json, 'marlin_config.json', marlin_zip)
    except:
        pass

    # Extract "enabled" #define lines by scraping the configuration files.
    # This data also contains the @section for each option.
    conf_defines = {}
    conf_names = []
    for hpath in header_paths:
        # Get defines in the form of { name: { name:..., section:... }, ... }
        defines = enabled_defines(hpath)
        # Get all unique define names into a flat array
        conf_names += defines.keys()
        # Remember which file these defines came from
        conf_defines[hpath.split('/')[-1]] = defines

    # Get enabled config options based on running GCC to preprocess the config files.
    # The result is a list of line strings, each starting with '#define'.
    from preprocessor import run_preprocessor
    build_output = run_preprocessor(env)

    # Dumb regex to filter out some dumb macros
    r = re.compile(r"\(+(\s*-*\s*_.*)\)+")

    # Extract all the #define lines in the build output as key/value pairs
    build_defines = {}
    for line in build_output:
        # Split the define from the value.
        key_val = line[8:].strip().decode().split(' ')
        key, value = key_val[0], ' '.join(key_val[1:])
        # Ignore values starting with two underscore, since it's low level
        if len(key) > 2 and key[0:2] == "__": continue
        # Ignore values containing parentheses (likely a function macro)
        if '(' in key and ')' in key: continue
        # Then filter dumb values
        if r.match(value): continue

        build_defines[key] = value if len(value) else ""
=======
def compress_file(filepath, outpath):
    with zipfile.ZipFile(outpath, 'w', compression=zipfile.ZIP_BZIP2, compresslevel=9) as zipf:
        zipf.write(filepath, compress_type=zipfile.ZIP_BZIP2, compresslevel=9)

#
# Compute the build signature. The idea is to extract all defines in the configuration headers
# to build a unique reversible signature from this build so it can be included in the binary
# We can reverse the signature to get a 1:1 equivalent configuration file
#
def compute_build_signature(env):
    if 'BUILD_SIGNATURE' in env:
        return

    # Definitions from these files will be kept
    files_to_keep = [ 'Marlin/Configuration.h', 'Marlin/Configuration_adv.h' ]

    build_path = Path(env['PROJECT_BUILD_DIR'], env['PIOENV'])

    # Check if we can skip processing
    hashes = ''
    for header in files_to_keep:
        hashes += get_file_sha256sum(header)[0:10]

    marlin_json = build_path / 'marlin_config.json'
    marlin_zip = build_path / 'mc.zip'

    # Read existing config file
    try:
        with marlin_json.open() as infile:
            conf = json.load(infile)
            if conf['__INITIAL_HASH'] == hashes:
                # Same configuration, skip recomputing the building signature
                compress_file(marlin_json, marlin_zip)
                return
    except:
        pass

    # Get enabled config options based on preprocessor
    from preprocessor import run_preprocessor
    complete_cfg = run_preprocessor(env)

    # Dumb #define extraction from the configuration files
    conf_defines = {}
    all_defines = []
    for header in files_to_keep:
        defines = extract_defines(header)
        # To filter only the define we want
        all_defines += defines
        # To remember from which file it cames from
        conf_defines[header.split('/')[-1]] = defines

    r = re.compile(r"\(+(\s*-*\s*_.*)\)+")

    # First step is to collect all valid macros
    defines = {}
    for line in complete_cfg:

        # Split the define from the value
        key_val = line[8:].strip().decode().split(' ')
        key, value = key_val[0], ' '.join(key_val[1:])

        # Ignore values starting with two underscore, since it's low level
        if len(key) > 2 and key[0:2] == "__" :
            continue
        # Ignore values containing a parenthesis (likely a function macro)
        if '(' in key and ')' in key:
            continue

        # Then filter dumb values
        if r.match(value):
            continue

        defines[key] = value if len(value) else ""
>>>>>>> upstream/bugfix-2.0.x

    #
    # Continue to gather data for CONFIGURATION_EMBEDDING or CONFIG_EXPORT
    #
<<<<<<< HEAD
    if not ('CONFIGURATION_EMBEDDING' in build_defines or 'CONFIG_EXPORT' in build_defines):
        return

    # Filter out useless macros from the output
    cleaned_build_defines = {}
    for key in build_defines:
        # Remove all boards now
        if key.startswith("BOARD_") and key != "BOARD_INFO_NAME": continue
        # Remove all keys ending by "_T_DECLARED" as it's a copy of extraneous system stuff
        if key.endswith("_T_DECLARED"): continue
        # Remove keys that are not in the #define list in the Configuration list
        if key not in conf_names + [ 'DETAILED_BUILD_VERSION', 'STRING_DISTRIBUTION_DATE' ]: continue
        # Add to a new dictionary for simplicity
        cleaned_build_defines[key] = build_defines[key]

    # And we only care about defines that (most likely) came from the config files
    # Build a dictionary of dictionaries with keys: 'name', 'section', 'value'
    # { 'file1': { 'option': { 'name':'option', 'section':..., 'value':... }, ... }, 'file2': { ... } }
    real_config = {}
    for header in conf_defines:
        real_config[header] = {}
        for key in cleaned_build_defines:
            if key in conf_defines[header]:
                if key[0:2] == '__': continue
                val = cleaned_build_defines[key]
                real_config[header][key] = { 'file':header, 'name': key, 'value': val, 'section': conf_defines[header][key]['section']}

    def tryint(key):
        try: return int(build_defines[key])
        except: return 0

    # Get the CONFIG_EXPORT value and do an extended dump if > 100
    # For example, CONFIG_EXPORT 102 will make a 'config.ini' with a [config:] group for each schema @section
    config_dump = tryint('CONFIG_EXPORT')
    extended_dump = config_dump > 100
    if extended_dump: config_dump -= 100
=======
    if not ('CONFIGURATION_EMBEDDING' in defines or 'CONFIG_EXPORT' in defines):
        return

    # Second step is to filter useless macro
    resolved_defines = {}
    for key in defines:
        # Remove all boards now
        if key.startswith("BOARD_") and key != "BOARD_INFO_NAME":
            continue
        # Remove all keys ending by "_NAME" as it does not make a difference to the configuration
        if key.endswith("_NAME") and key != "CUSTOM_MACHINE_NAME":
            continue
        # Remove all keys ending by "_T_DECLARED" as it's a copy of extraneous system stuff
        if key.endswith("_T_DECLARED"):
            continue
        # Remove keys that are not in the #define list in the Configuration list
        if key not in all_defines + [ 'DETAILED_BUILD_VERSION', 'STRING_DISTRIBUTION_DATE' ]:
            continue

        # Don't be that smart guy here
        resolved_defines[key] = defines[key]

    # Generate a build signature now
    # We are making an object that's a bit more complex than a basic dictionary here
    data = {}
    data['__INITIAL_HASH'] = hashes
    # First create a key for each header here
    for header in conf_defines:
        data[header] = {}

    # Then populate the object where each key is going to (that's a O(N^2) algorithm here...)
    for key in resolved_defines:
        for header in conf_defines:
            if key in conf_defines[header]:
                data[header][key] = resolved_defines[key]

    # Every python needs this toy
    def tryint(key):
        try:
            return int(defines[key])
        except:
            return 0

    config_dump = tryint('CONFIG_EXPORT')
>>>>>>> upstream/bugfix-2.0.x

    #
    # Produce an INI file if CONFIG_EXPORT == 2
    #
    if config_dump == 2:
        print("Generating config.ini ...")
<<<<<<< HEAD

        ini_fmt = '{0:40} = {1}'
        ext_fmt = '{0:40}   {1}'
        ignore = ('CONFIGURATION_H_VERSION', 'CONFIGURATION_ADV_H_VERSION', 'CONFIG_EXAMPLES_DIR', 'CONFIG_EXPORT')

        if extended_dump:
            # Extended export will dump config options by section

            # We'll use Schema class to get the sections
            try:
                conf_schema = schema.extract()
            except Exception as exc:
                print("Error: " + str(exc))
                exit(1)

            # Then group options by schema @section
            sections = {}
            for header in real_config:
                for name in real_config[header]:
                    #print(f"  name: {name}")
                    if name not in ignore:
                        ddict = real_config[header][name]
                        #print(f"   real_config[{header}][{name}]:", ddict)
                        sect = ddict['section']
                        if sect not in sections: sections[sect] = {}
                        sections[sect][name] = ddict

            # Get all sections as a list of strings, with spaces and dashes replaced by underscores
            long_list = [ re.sub(r'[- ]+', '_', x).lower() for x in sections.keys() ]
            # Make comma-separated lists of sections with 64 characters or less
            sec_lines = []
            while len(long_list):
                line = long_list.pop(0) + ', '
                while len(long_list) and len(line) + len(long_list[0]) < 64 - 1:
                    line += long_list.pop(0) + ', '
                sec_lines.append(line.strip())
            sec_lines[-1] = sec_lines[-1][:-1] # Remove the last comma

        else:
            sec_lines = ['all']

        # Build the ini_use_config item
        sec_list = ini_fmt.format('ini_use_config', sec_lines[0])
        for line in sec_lines[1:]: sec_list += '\n' + ext_fmt.format('', line)

        config_ini = build_path / 'config.ini'
        with config_ini.open('w') as outfile:
            filegrp = { 'Configuration.h':'config:basic', 'Configuration_adv.h':'config:advanced' }
            vers = build_defines["CONFIGURATION_H_VERSION"]
            dt_string = datetime.now().strftime("%Y-%m-%d at %H:%M:%S")

            outfile.write(
f'''#
# Marlin Firmware
# config.ini - Options to apply before the build
#
# Generated by Marlin build on {dt_string}
#
[config:base]
#
# ini_use_config - A comma-separated list of actions to apply to the Configuration files.
#                  The actions will be applied in the listed order.
#  - none
#    Ignore this file and don't apply any configuration options
#
#  - base
#    Just apply the options in config:base to the configuration
#
#  - minimal
#    Just apply the options in config:minimal to the configuration
#
#  - all
#    Apply all 'config:*' sections in this file to the configuration
#
#  - another.ini
#    Load another INI file with a path relative to this config.ini file (i.e., within Marlin/)
#
#  - https://me.myserver.com/path/to/configs
#    Fetch configurations from any URL.
#
#  - example/Creality/Ender-5 Plus @ bugfix-2.1.x
#    Fetch example configuration files from the MarlinFirmware/Configurations repository
#    https://raw.githubusercontent.com/MarlinFirmware/Configurations/bugfix-2.1.x/config/examples/Creality/Ender-5%20Plus/
#
#  - example/default @ release-2.0.9.7
#    Fetch default configuration files from the MarlinFirmware/Configurations repository
#    https://raw.githubusercontent.com/MarlinFirmware/Configurations/release-2.0.9.7/config/default/
#
#  - [disable]
#    Comment out all #defines in both Configuration.h and Configuration_adv.h. This is useful
#    to start with a clean slate before applying any config: options, so only the options explicitly
#    set in config.ini will be enabled in the configuration.
#
#  - [flatten] (Not yet implemented)
#    Produce a flattened set of Configuration.h and Configuration_adv.h files with only the enabled
#    #defines and no comments. A clean look, but context-free.
#
{sec_list}
{ini_fmt.format('ini_config_vers', vers)}
'''         )

            if extended_dump:

                # Loop through the sections
                for skey in sorted(sections):
                    #print(f"  skey: {skey}")
                    sani = re.sub(r'[- ]+', '_', skey).lower()
                    outfile.write(f"\n[config:{sani}]\n")
                    opts = sections[skey]
                    for name in sorted(opts):
                        val = opts[name]['value']
                        if val == '': val = 'on'
                        #print(f"  {name} = {val}")
                        outfile.write(ini_fmt.format(name.lower(), val) + '\n')

            else:

                # Standard export just dumps config:basic and config:advanced sections
                for header in real_config:
                    outfile.write(f'\n[{filegrp[header]}]\n')
                    for name in sorted(real_config[header]):
                        if name not in ignore:
                            val = real_config[header][name]['value']
                            if val == '': val = 'on'
                            outfile.write(ini_fmt.format(name.lower(), val) + '\n')

    #
    # CONFIG_EXPORT 3 = schema.json, 4 = schema.yml
=======
        config_ini = build_path / 'config.ini'
        with config_ini.open('w') as outfile:
            ignore = ('CONFIGURATION_H_VERSION', 'CONFIGURATION_ADV_H_VERSION', 'CONFIG_EXPORT')
            filegrp = { 'Configuration.h':'config:basic', 'Configuration_adv.h':'config:advanced' }
            vers = defines["CONFIGURATION_H_VERSION"]
            dt_string = datetime.now().strftime("%Y-%m-%d at %H:%M:%S")
            ini_fmt = '{0:40}{1}\n'
            outfile.write(
                '#\n'
                + '# Marlin Firmware\n'
                + '# config.ini - Options to apply before the build\n'
                + '#\n'
                + f'# Generated by Marlin build on {dt_string}\n'
                + '#\n'
                + '\n'
                + '[config:base]\n'
                + ini_fmt.format('ini_use_config', ' = all')
                + ini_fmt.format('ini_config_vers', f' = {vers}')
            )
            # Loop through the data array of arrays
            for header in data:
                if header.startswith('__'):
                    continue
                outfile.write('\n[' + filegrp[header] + ']\n')
                for key in sorted(data[header]):
                    if key not in ignore:
                        val = 'on' if data[header][key] == '' else data[header][key]
                        outfile.write(ini_fmt.format(key.lower(), ' = ' + val))

    #
    # Produce a schema.json file if CONFIG_EXPORT == 3
>>>>>>> upstream/bugfix-2.0.x
    #
    if config_dump >= 3:
        try:
            conf_schema = schema.extract()
        except Exception as exc:
            print("Error: " + str(exc))
            conf_schema = None

        if conf_schema:
            #
<<<<<<< HEAD
            # 3 = schema.json
=======
            # Produce a schema.json file if CONFIG_EXPORT == 3
>>>>>>> upstream/bugfix-2.0.x
            #
            if config_dump in (3, 13):
                print("Generating schema.json ...")
                schema.dump_json(conf_schema, build_path / 'schema.json')
                if config_dump == 13:
                    schema.group_options(conf_schema)
                    schema.dump_json(conf_schema, build_path / 'schema_grouped.json')

            #
<<<<<<< HEAD
            # 4 = schema.yml
=======
            # Produce a schema.yml file if CONFIG_EXPORT == 4
>>>>>>> upstream/bugfix-2.0.x
            #
            elif config_dump == 4:
                print("Generating schema.yml ...")
                try:
                    import yaml
                except ImportError:
                    env.Execute(env.VerboseAction(
                        '$PYTHONEXE -m pip install "pyyaml"',
                        "Installing YAML for schema.yml export",
                    ))
                    import yaml
                schema.dump_yaml(conf_schema, build_path / 'schema.yml')

<<<<<<< HEAD
    #
    # Produce a JSON file for CONFIGURATION_EMBEDDING or CONFIG_EXPORT == 1
    # Skip if an identical JSON file was already present.
    #
    if not same_hash and (config_dump == 1 or 'CONFIGURATION_EMBEDDING' in build_defines):
        with marlin_json.open('w') as outfile:

            json_data = {}
            if extended_dump:
                print("Extended dump ...")
                for header in real_config:
                    confs = real_config[header]
                    json_data[header] = {}
                    for name in confs:
                        c = confs[name]
                        s = c['section']
                        if s not in json_data[header]: json_data[header][s] = {}
                        json_data[header][s][name] = c['value']
            else:
                for header in real_config:
                    conf = real_config[header]
                    #print(f"real_config[{header}]", conf)
                    for name in conf:
                        json_data[name] = conf[name]['value']

            json_data['__INITIAL_HASH'] = hashes

            # Append the source code version and date
            json_data['VERSION'] = {
                'DETAILED_BUILD_VERSION': cleaned_build_defines['DETAILED_BUILD_VERSION'],
                'STRING_DISTRIBUTION_DATE': cleaned_build_defines['STRING_DISTRIBUTION_DATE']
            }
            try:
                curver = subprocess.check_output(["git", "describe", "--match=NeVeRmAtCh", "--always"]).strip()
                json_data['VERSION']['GIT_REF'] = curver.decode()
            except:
                pass

            json.dump(json_data, outfile, separators=(',', ':'))
=======
    # Append the source code version and date
    data['VERSION'] = {}
    data['VERSION']['DETAILED_BUILD_VERSION'] = resolved_defines['DETAILED_BUILD_VERSION']
    data['VERSION']['STRING_DISTRIBUTION_DATE'] = resolved_defines['STRING_DISTRIBUTION_DATE']
    try:
        curver = subprocess.check_output(["git", "describe", "--match=NeVeRmAtCh", "--always"]).strip()
        data['VERSION']['GIT_REF'] = curver.decode()
    except:
        pass

    #
    # Produce a JSON file for CONFIGURATION_EMBEDDING or CONFIG_EXPORT == 1
    #
    if config_dump == 1 or 'CONFIGURATION_EMBEDDING' in defines:
        with marlin_json.open('w') as outfile:
            json.dump(data, outfile, separators=(',', ':'))
>>>>>>> upstream/bugfix-2.0.x

    #
    # The rest only applies to CONFIGURATION_EMBEDDING
    #
<<<<<<< HEAD
    if not 'CONFIGURATION_EMBEDDING' in build_defines:
        (build_path / 'mc.zip').unlink(missing_ok=True)
        return

    # Compress the JSON file as much as we can
    if not same_hash:
        compress_file(marlin_json, 'marlin_config.json', marlin_zip)

    # Generate a C source file containing the entire ZIP file as an array
=======
    if not 'CONFIGURATION_EMBEDDING' in defines:
        return

    # Compress the JSON file as much as we can
    compress_file(marlin_json, marlin_zip)

    # Generate a C source file for storing this array
>>>>>>> upstream/bugfix-2.0.x
    with open('Marlin/src/mczip.h','wb') as result_file:
        result_file.write(
              b'#ifndef NO_CONFIGURATION_EMBEDDING_WARNING\n'
            + b'  #warning "Generated file \'mc.zip\' is embedded (Define NO_CONFIGURATION_EMBEDDING_WARNING to suppress this warning.)"\n'
            + b'#endif\n'
            + b'const unsigned char mc_zip[] PROGMEM = {\n '
        )
        count = 0
        for b in (build_path / 'mc.zip').open('rb').read():
            result_file.write(b' 0x%02X,' % b)
            count += 1
<<<<<<< HEAD
            if count % 16 == 0: result_file.write(b'\n ')
        if count % 16: result_file.write(b'\n')
        result_file.write(b'};\n')

if __name__ == "__main__":
    # Build required. From command line just explain usage.
    print("Use schema.py to export JSON and YAML from the command-line.")
    print("Build Marlin with CONFIG_EXPORT 2 to export 'config.ini'.")
=======
            if count % 16 == 0:
                result_file.write(b'\n ')
        if count % 16:
            result_file.write(b'\n')
        result_file.write(b'};\n')
>>>>>>> upstream/bugfix-2.0.x
