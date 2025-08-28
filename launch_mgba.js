#!/usr/bin/env node

const { spawn } = require('child_process');
const path = require('path');

// Path to the ROM file
const romPath = path.join(__dirname, 'pokeemerald-expansion', 'pokeemerald.gba');

// Launch mGBA with the ROM
console.log('Launching mGBA with ROM:', romPath);

const mgba = spawn('/usr/games/mgba-qt', [romPath], {
    stdio: 'inherit'
});

mgba.on('close', (code) => {
    console.log(`mGBA exited with code ${code}`);
});

mgba.on('error', (err) => {
    console.error('Failed to start mGBA:', err.message);
});