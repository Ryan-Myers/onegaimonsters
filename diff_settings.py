def apply(config, args):
    config["baseimg"] = "onegaimonsters.z64"
    config["myimg"] = "build/onegaimonsters.z64"
    config["mapfile"] = "build/onegaimonsters.map"
    config["source_directories"] = ["src"]
    config["show_line_numbers_default"] = True
    config["expected_dir"] = "expected/"
