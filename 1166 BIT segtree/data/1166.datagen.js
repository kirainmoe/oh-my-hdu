const title = "1166";
const exeName = "1166.fs.exe";
const stdName = "1166.std.exe";
const dataNum = 15;

const fs = require('fs'),
			exec = require('child_process').execSync;

const commands = [
	'Add', 'Query', 'Sub'
];

const generator = () => {
	let input = "";
	let cases = Math.floor(Math.random() * 10);
	if (cases == 0)
		cases = 1;
	input += cases + "\n";

	while (cases--)
	{
		let n = Math.ceil(Math.random() * 10000);
		if (n == 0)
			n = 100;
		input += n + "\n";
		for (let i = 1; i <= n; i++)
		{
			const cur = Math.ceil(Math.random() * 50);
			input += cur;
			if (i != n)
				input += " ";
			else
				input += "\n";
		}

		let cmds = Math.ceil(Math.random() * 10000);
		while (cmds--)
		{
			let target1 = Math.floor(Math.random() * n),
						target2 = Math.floor(Math.random() * n);

			if (target1 == 0)
				target1 = 1;
			if (target2 == 0)
				target2 = 1;

			if (target1 > target2) {
				const tmp = target2;
				target2 = target1;
				target1 = tmp;
			}

			if (target1 == target2) {
				if (target2 != n)
					target2++;
				else
					target1--;
			}

			const num = Math.floor(Math.random() * 30);
			const operation = Math.random();

			if (operation < 0.5) {
				input += "Query " + target1 + " " + target2 + "\n";
			} else if (operation >= 0.5 && operation <= 0.8) {
				input += "Add " + target1 + " "  + num + "\n";
			} else {
				input += "Sub " + target1 + " " + num + "\n";
			}
		}
		input += "End\n";
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