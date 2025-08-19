import argparse
import os
import shutil
import sys
from pathlib import Path
from tqdm import tqdm
import gc

IMAGE_EXTENSIONS = {".jpg", ".jpeg", ".png", 
                    ".gif", ".tif", ".tiff", 
                    ".bmp", ".heic", ".webp", 
                    ".mp4", ".mov", ".avi", 
                    ".mkv"}

def is_file(path: Path, extra_exts=()):
    ext = path.suffix.lower()
    return ext in IMAGE_EXTENSIONS or ext in {e.lower() for e in extra_exts}

def gather_image_files(root: Path, extra_exts=()):
    files = []
    for dirpath, filenames in os.walk(root):
        for name in filenames:
            p = Path(dirpath) / name
            try:
                if is_file(p, extra_exts):
                    files.append(p)
            except Exception:
                pass
    return files

def copy_images_to_folder(files, dest_folder: Path):
    dest_folder.mkdir(parents=True, exist_ok=True)
    name_count = {}
    for src in tqdm(files, desc="Copying files"):
        base = src.name
        # If duplicate, add a counter
        if base not in name_count:
            name_count[base] = 1
            dest = dest_folder / base
        else:
            name_count[base] += 1
            stem, ext = os.path.splitext(base)
            dest = dest_folder / f"{stem}_{name_count[base]}{ext}"
        # Copy file using context manager for explicit file closing
        with src.open('rb') as fsrc, open(dest, 'wb') as fdst:
            shutil.copyfileobj(fsrc, fdst)
        # Explicitly delete references and collect garbage
        del fsrc, fdst
        gc.collect()

def parse_args(argv):
    p = argparse.ArgumentParser(description="Copy all images from a folder tree into a single folder.")
    p.add_argument("root", help="Root folder to scan (e.g., F:\\)")
    p.add_argument("--output", "-o", required=True, help="Destination folder for all images.")
    p.add_argument("--ext", "-e", action="append", help="Additional image extensions to include (e.g. .psd). Can be used multiple times")
    p.add_argument("--dry-run", action="store_true", help="List files that would be copied without copying.")
    return p.parse_args(argv)

def main(argv=None):
    argv = argv if argv is not None else sys.argv[1:]
    args = parse_args(argv)
    root = Path(args.root)
    dest = Path(args.output)
    extra_exts = args.ext or []
    files = gather_image_files(root, extra_exts)
    print(f"Found {len(files)} image files.")
    if args.dry_run:
        for f in files:
            print(f)
        return 0
    copy_images_to_folder(files, dest)
    print(f"Copied {len(files)} images to {dest}")
    return 0

if __name__ == "__main__":
    sys.exit(main())