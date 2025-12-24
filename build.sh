#!/usr/bin/env bash
# Fetch the latest version of the library
fetch() {
if [ -d "ggformat" ]; then return; fi
URL="https://github.com/mikejsavage/ggformat/archive/refs/heads/master.zip"
ZIP="${URL##*/}"
DIR="ggformat-master"
mkdir -p .build
cd .build

# Download the release
if [ ! -f "$ZIP" ]; then
  echo "Downloading $ZIP from $URL ..."
  curl -L "$URL" -o "$ZIP"
  echo ""
fi

# Unzip the release
if [ ! -d "$DIR" ]; then
  echo "Unzipping $ZIP to .build/$DIR ..."
  cp "$ZIP" "$ZIP.bak"
  unzip -q "$ZIP"
  rm "$ZIP"
  mv "$ZIP.bak" "$ZIP"
  echo ""
fi
cd ..

# Copy the libs to the package directory
echo "Copying libs to ggformat/ ..."
rm -rf ggformat
mkdir -p ggformat
cp -f ".build/$DIR/ggformat.h"   ggformat/
cp -f ".build/$DIR/ggformat.cpp" ggformat/
echo ""
}


# Test the project
test() {
echo "Running 01-dynamic-greetings.cxx ..."
clang -I. -o 01.exe examples/01-dynamic-greetings.cxx    && ./01.exe && echo -e "\n"
echo "Running 02-file-output.cxx ..."
clang -I. -o 02.exe examples/02-file-output.cxx          && ./02.exe && echo -e "\n"
echo "Running 03-advanced-formatting.cxx ..."
clang -I. -o 03.exe examples/03-advanced-formatting.cxx  && ./03.exe && echo -e "\n"
}


# Main script
if [[ "$1" == "test" ]]; then test
elif [[ "$1" == "fetch" ]]; then fetch
else echo "Usage: $0 {fetch|test}"; fi
