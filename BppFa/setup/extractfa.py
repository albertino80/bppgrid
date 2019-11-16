"""
Convert FontAwesome's `icons.json` to QML.

This script creates a QML component which defines
constants for all FontAwesome icons listed in the file
`icons.json` in the FontAwesome package.
"""

import sys

def getIconName(key):
    name = "fa_" + key.replace("-", "_")
    return name

def _main(argv):
    import json
    if len(argv) != 2:
        print("Usage:")
        msg = "    {} icons.json"
        msg = msg.format(argv[0])
        print(msg)
        sys.exit(1)
    with open(argv[1], "r") as file:
        icons = json.load(file)

    lines = []
    prop = '	Q_PROPERTY(QString {} READ get_{} CONSTANT)'
    varName = '	const QString {} = QChar(0x{});'
    getter = '	const QString& get_{}() const {{return {};}}'

    lines.append('public:')
    for key in icons:
        icovar = getIconName(key)
        code = icons[key]["unicode"]

        line = prop.format(icovar, icovar)
        lines.append(line)

    for key in icons:
        icovar = getIconName(key)
        code = icons[key]["unicode"]

        line = getter.format(icovar, icovar)
        lines.append(line)

    lines.append('protected:')
    for key in icons:
        icovar = getIconName(key)
        code = icons[key]["unicode"]

        line = varName.format(icovar, code)
        lines.append(line)

    with open("fa_class.h", "w") as file:
        file.write("\n".join(lines))

if __name__ == '__main__':
    _main(sys.argv)