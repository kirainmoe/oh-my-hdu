const title = "1004";
const exeName = "1004-fs.exe";
const dataNum = 10;

const fs = require('fs'),
			exec = require('child_process').execSync;

const colours = [
	'red', 'yellow', 'pink', 'blue', 'grey', 'black', 'white', 'green', 'purple', 'silver', 'gold', 'orange'
];

const generator = () => {
	let input = "";
	let cases = Math.floor(Math.random() * 10);
	if (cases == 0)
		cases = 1;

	const colorSize = colours.length;

	while (cases--)
	{
		let n = Math.floor(Math.random() * 1000);
		if (n == 0)
			n = 1;
		input += String(n);
		input += "\n";
		for (let i = 0; i < n; i++)
		{
			const index = Math.floor(Math.random() * colorSize);
			input += colours[index];
			input += "\n";
		}
		if (cases != 0)
		{
			input += "\n";
		}
		else
		{
			input += "0";
		}
	}
	return input;
};

for (let i = 1; i <= dataNum; i++)
{
	const currentData = generator();
	fs.writeFileSync(i + '.in', currentData);
	fs.writeFileSync(title + '.in', currentData);
	exec(exeName);

	const output = fs.readFileSync(title + '.out');
	fs.writeFileSync(i + '.out', output);
	fs.unlinkSync(title + '.in');
	fs.unlinkSync(title + '.out');

	console.log("Testcase " + i + " generated successfully.");
}