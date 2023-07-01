const fs = require("fs");

function factorial(n) {
  if (n === 0 || n === 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

function createFileWithLines(lines, fileName) {
  const startTime = new Date();

  const fileContent = [];
  for (let i = 1; i <= lines; i++) {
    fileContent.push(`factorial of ${i} is ${factorial(i)}`);
    // fileContent.push(`line ${i}`);
  }

  const contentToWrite = fileContent.join("\n");

  fs.writeFileSync(fileName, contentToWrite);

  const endTime = new Date();
  const duration = endTime - startTime;
  console.log(`File ${fileName} created successfully with ${lines} lines.`);
  console.log(`Time taken: ${duration} milliseconds`);
}

if (process.argv.length < 4) {
  console.log("Usage: node main.js <lines> <fileName>");
  process.exit(1);
}

const lines = parseInt(process.argv[2]);
const fileName = process.argv[3];

createFileWithLines(lines, fileName);
