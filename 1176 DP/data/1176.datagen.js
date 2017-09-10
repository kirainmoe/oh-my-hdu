const title = "1176";
const exeName = "1176.fs.exe";
const stdName = "1176.std.exe";
const dataNum = 15;

const fs = require('fs'),
			exec = require('child_process').execSync;

const generator = () => {
	let input = "";
	let cases = Math.floor(Math.random() * 10);
	if (cases == 0)
		cases = 1;

	while (cases--)
	{
		let n = Math.floor(Math.random() * 30000);
		if (n == 0)
			n = 200;
		input += n + "\n";
		while (n--)
		{
			let x = Math.floor(Math.random() * 10),
					t = Math.floor(Math.random() * 80000);
			input += x + ' ' + t + '\n';
		}
	}
	input += "0\n";
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
		console.log('Will regenerate this testcase.');
		i--;
	}	
}