#!/bin/bash
# ABOUTME: Build helper script for Pokemon Infinite Emerald

set -e

cd "$(dirname "$0")/pokeemerald-expansion"

case "${1:-build}" in
    "clean")
        echo "🧹 Cleaning build artifacts..."
        make clean
        ;;
    "tools")
        echo "🔧 Building development tools..."
        make tools
        ;;
    "build"|"")
        echo "🏗️ Building Pokemon Infinite Emerald ROM..."
        make -j$(nproc)
        echo "✅ Build complete! ROM: pokeemerald.gba"
        ;;
    "test")
        echo "🧪 Building and testing..."
        make -j$(nproc)
        if command -v mgba-qt &> /dev/null; then
            echo "🎮 Launching in mGBA..."
            mgba-qt pokeemerald.gba &
        else
            echo "⚠️ mGBA not installed. Install with: sudo apt install mgba-qt"
        fi
        ;;
    "help"|"-h"|"--help")
        echo "Pokemon Infinite Emerald Build Script"
        echo ""
        echo "Usage: $0 [command]"
        echo ""
        echo "Commands:"
        echo "  build    Build the ROM (default)"
        echo "  clean    Clean build artifacts"
        echo "  tools    Build development tools"
        echo "  test     Build and launch in emulator"
        echo "  help     Show this help"
        ;;
    *)
        echo "❌ Unknown command: $1"
        echo "Run '$0 help' for available commands"
        exit 1
        ;;
esac