const title = "1024";
const exeName = "1024-fs.exe";
const stdName = "1024-std.exe";
const dataNum = 15;

const fs = require('fs'),
			exec = require('child_process').execSync;

const generator = () => {
	let input = "";
	let cases = Math.floor(Math.random() * 8);
	if (cases == 0)
		cases = 1;

	while (cases--)
	{
		let m = Math.floor(Math.random() * 8);
		let n = Math.floor(Math.random() * 10000);
		if (n == 0)
			n = 20;
		if (m == 0)
			m = 2;
		input += m + " " + n + " ";
		for (let i = 1; i <= n; i++)
		{
			let index = Math.floor(Math.random() * 1000);
			const isNegative = Math.random();
			if (isNegative <= 0.1)
			{
				index = -index;
			}
			input += index;
			if (i != n)
				input += " ";
			else
				input += "\n";
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
	exec(stdName);

	const output = fs.readFileSync(title + '.out');
	const stdOutput = fs.readFileSync(title + '.std.out');

	fs.writeFileSync(i + '.out', output);
	fs.unlinkSync(title + '.in');
	fs.unlinkSync(title + '.out');
	fs.unlinkSync(title + '.std.out');

	console.log("Testcase " + i + " generated successfully.");
	if (String(output) == String(stdOutput))
	{
		console.log("Output verified, no difference encounted.");
	}
	else
	{
		console.log("Your output seems to be different from std output.");
		console.log(' - Your output is:' + output);
		console.log(' - While std\'s output is:' + stdOutput);
	}	
}