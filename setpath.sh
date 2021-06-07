# This script adds the build directory to the system PATH and python
# path for the bindings.
# It is inspired by https://github.com/mitsuba-renderer/mitsuba2
REMESHER_DIR=""
if [ "$BASH_VERSION" ]; then
    if [[ "${BASH_SOURCE[0]}" != "${0}" ]]; then
        REMESHER_DIR=$(dirname "$BASH_SOURCE")
        REMESHER_DIR=$(builtin cd "$REMESHER_DIR"; builtin pwd)
    fi
elif [ "$ZSH_VERSION" ]; then
    if [[ -n ${(M)zsh_eval_context:#file} ]]; then
        REMESHER_DIR=$(dirname "$0:A")
    fi
fi

if [ -z "$REMESHER_DIR" ]; then
    echo "This script must be executed via the 'source' command, i.e.:"
    echo "$ source ${0}"
    exit 0
fi

export PYTHONPATH="$REMESHER_DIR:$PYTHONPATH"
export PATH="$REMESHER_DIR:$PATH"
