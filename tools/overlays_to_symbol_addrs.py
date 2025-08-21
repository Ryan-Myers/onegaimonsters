import sys
import yaml

def make_name(seg):
    """Generate a safe name for a segment."""
    if "name" in seg:
        return seg["name"]
    start = seg.get("start")
    seg_type = seg.get("type", "seg")
    return f"{seg_type}_{start:X}"

def main(yaml_path):
    with open(yaml_path, "r") as f:
        config = yaml.safe_load(f)

    segments = config.get("segments", [])

    overlays = [
        seg for seg in segments
        if isinstance(seg, dict) and seg.get("type") in ("code", "bin")
    ]

    for i, seg in enumerate(overlays):
        name = make_name(seg)
        start = seg["start"]
        end = overlays[i + 1]["start"] if i + 1 < len(overlays) else None

        if end is not None:
            size = end - start
            print(f"{name}_ROM_START = 0x{start:X}; // name_end:{name}_ROM_END size:0x{size:X}")
        else:
            print(f"{name}_ROM_START = 0x{start:X}; // name_end:{name}_ROM_END size:???")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} splat.yaml")
        sys.exit(1)
    main(sys.argv[1])
