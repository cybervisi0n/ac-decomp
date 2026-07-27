python3 tools/download_tool.py compilers dtk-tools/compilers --tag 20251118
python3 tools/download_tool.py dtk dtk-tools/dtk --tag v1.6.2



if [[ "$(uname -s)" =~ ^MSYS_NT.* ]]; then
	# Windows specific setup
    mv dtk-tools/dtk dtk-tools/dtk.exe

else
	# Linux specific setup
    python3 tools/download_tool.py wibo dtk-tools/wibo --tag 1.2.0
fi