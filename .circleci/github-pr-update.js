#!/usr/bin/env node

const bot = require("./circle-github-bot/").create();

bot.comment(process.env.GH_AUTH_TOKEN, `
Thank you for contributing EusLisp documentation<br>
Please check latest documents before merging<br>

PDF version of English manual: <strong>${bot.artifactLink('artifacts/manual.pdf', 'manual.pdf')}</strong>
PDF version of Japanese jmanual: <strong>${bot.artifactLink('artifacts/jmanual.pdf', 'jmanual.pdf')}</strong>
HTML version of English manual: <strong>${bot.artifactLink('artifacts/html/manual.html', 'manual.html')}</strong>
HTML version of Japanese manual: <strong>${bot.artifactLink('artifacts/html/jmanual.html', 'jmanual.html')}</strong>
Sphinx (ReST) version of English manual: <strong>${bot.artifactLink('artifacts/rst/html/manual.html', 'manual.rst')}</strong>
`);
