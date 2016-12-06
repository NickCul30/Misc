using Discord;
using Discord.Commands;
using Discord.Audio;

using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NickBot{
    class MyBot{
        DiscordClient discord;
        CommandService commands;
        AudioService audio;



        public MyBot(){
            discord = new DiscordClient(x =>
            {
                x.LogLevel = LogSeverity.Info;
                x.LogHandler = Log;
            });

            discord.UsingCommands(x =>
            {
                x.PrefixChar = '!';
                x.AllowMentionPrefix = true;
            });

            commands = discord.GetService<CommandService>();


            //Secret
            //================
            commands.CreateCommand("thank you")
                .Alias(new String[] { "thanks", "ty" })
                .Do(async (e) =>
                {
                    await e.Channel.SendMessage("No Prob Bob.");
                });

            commands.CreateCommand("beemovie")
                .Do(async (e) =>
                {
                    await e.Channel.SendMessage("If you think about it\nBee Movie could have never existed\nBecause of one simply question everyone looked over\nWhere is the queen bee ?\nBarry does say We're all cousins because in the real world.All bees are born from the queen bee, but that doesn't give us enough evidence that there was actually a queen bee for there had to be larvae egg's somewhere in the movie because bees are always being born because they always die.We see an example of this when Adam tries to find a job and doesn't get it because it's full but 1 second later a job opens up because a bee had just died.If there aren't any larvae eggs or any larvae egg shells atleast, then where is the queen bee? If she didn't exist, the Bee Movie couldn't never exist. Take that Jerry Seinfeld!");
                });


            //Help
            //================
            commands.CreateCommand("help")
                .Do(async (e) =>
                {
                    String[] keyWords = { "Help()", "Pow(int x, int n)", "ZigZag(String s, int n)", "IsPowerOfTwo(int n)", "AddBinary (Base2 int b1, Base2 int b2)", "Guess Start(int r, int g)", "Guess(int n)" };
                    String[] disc = { "Shows all available commands", "Computes x^n", "String is written in a zigzag pattern (n rows) then read line by line (Incredibly useless)",
                                    "Checks if a number is an integer power of two", "Adds two binary numbers together", "Starts a game of higher/lower guess game", "Guesses a number, bot tells you if too high/low" };
                    String msg = "";
                    msg += "NickBot v1.00\n\nCommands\nBegin with '!', args seperated by space:\n";
                    for (int i = 0; i < keyWords.Length; i++)
                    {
                        msg += "\n" + (i + 1) + ". " + keyWords[i] + "\n\t" + disc[i] + "\n";
                    }
                    await e.Channel.SendMessage(msg);
                });


            //Pow x,n
            //================
            commands.CreateCommand("pow")
                .Parameter("num", ParameterType.Required)
                .Parameter("pow", ParameterType.Required)
                .Do(async (e) =>
                {
                    double num = Double.Parse(e.GetArg(0));
                    int pow = Int32.Parse(e.GetArg(1));
                    await e.Channel.SendMessage(myPow(num, pow) + "");
                });


            //ZigZag
            //================
            commands.CreateCommand("zigZag")
                .Parameter("s", ParameterType.Required)
                .Parameter("rows", ParameterType.Required)
                .Do(async (e) =>
                {
                    String str = e.GetArg(0);
                    int rows = Int32.Parse(e.GetArg(1));
                    await e.Channel.SendMessage(zigZag(str, rows) + "");
                });


            //IsPowerOfTwo
            //================
            commands.CreateCommand("IsPowerOfTwo")
                .Parameter("n", ParameterType.Required)
                .Do(async (e) =>
                {
                    int num = Int32.Parse(e.GetArg(0));
                    await e.Channel.SendMessage(isPowerOfTwo(num) + "");
                });


            //AddBinary
            //================
            commands.CreateCommand("AddBinary")
                .Parameter("bin1", ParameterType.Required)
                .Parameter("bin2", ParameterType.Required)
                .Do(async (e) =>
                {
                    String bin1 = e.GetArg(0);
                    String bin2 = e.GetArg(1);
                    await e.Channel.SendMessage(addBinary(bin1, bin2) + "");
                });


            //Guess
            //================
            commands.CreateGroup("guess", cgb =>
            {
                int gNum = 0, soFar = 0, target = 0, range = 0;
                Boolean canPlay = false;
                Random rnd = new Random();

                cgb.CreateCommand("start")
                        .Parameter("field", ParameterType.Required)
                        .Parameter("gNum", ParameterType.Required)
                        .Do(async e =>
                        {
                            range = Int32.Parse(e.GetArg(0));
                            gNum = Int32.Parse(e.GetArg(1));
                            canPlay = true;
                            target = rnd.Next(range) + 1;
                            soFar = 0;
                            await e.Channel.SendMessage("Game Started");
                        });

                cgb.CreateCommand("")
                        .Parameter("num", ParameterType.Required)
                        .Do(async e =>
                        {
                            if (canPlay)
                            {
                                int user = Int32.Parse(e.GetArg(0));
                                soFar++;
                                if (soFar == gNum && user != target)
                                {
                                    await e.Channel.SendMessage("You Lose, the number was " + target);
                                    canPlay = false;
                                }
                                else
                                {
                                    if (user > target) await e.Channel.SendMessage("Guess #" + soFar + " of " + gNum + ", Too High, guess again (1 - " + range + ")");
                                    else if (user < target) await e.Channel.SendMessage("Guess #" + soFar + " of " + gNum + ", Too Low, guess again (1 - " + range + ")");
                                    else
                                    {
                                        await e.Channel.SendMessage("Good Job, the number was " + target);
                                        canPlay = false;
                                    }
                                }
                            }
                            else await e.Channel.SendMessage("You must use !guess start (int r) (int g)\nr - Range of nums to guess (1 - r)\ng - Num of guesses before loss");
                            
                        });
            });


            //HangMan
            //================
            /*commands.CreateGroup("hm", cgb =>
            {
                String word = "";
                String soFar = "";
                char[] letters = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
                String[] pics = { "O", "O\n|", " O\n\|", " O\n\|/", " O\n\|/\n |", " O\n\|/\n |\n /", " O\n\|/\n |\n /\" };
                ArrayList wrong = new ArrayList();
                Boolean canPlay = false;

                cgb.CreateCommand("start")
                        .Parameter("word", ParameterType.Required)
                        .Do(async e =>
                        {
                            word = e.GetArg(0);
                            canPlay = true;
                            for(int i = 0; i < word.Length; i++)
                            {
                                soFar += "_";
                            }
                            await e.Channel.SendMessage("Game Started");
                        });

                cgb.CreateCommand("")
                        
                        .Parameter("letter", ParameterType.Required)
                        .Do(async e =>
                        {
                            if (canPlay)
                            {
                                char letter = char.Parse(e.GetArg(0).ToLower());

                                if (word.ToLower().Contains(letter)) {

                                }
                                else {

                                }
                            }
                            else
                            {
                                await e.Channel.SendMessage("You must use !hm start (String word) before guessing a letter");
                            }
                        });
            });*/


            //================
            discord.ExecuteAndWait(async () =>
            {
                await discord.Connect("MjUwMzQ5MjI3ODE5OTI1NTA0.CxTs3g.SfJDmwdCJFSep-mtP7q1g-_FC2Q", TokenType.Bot);
            });
        }

        //================
        //================
        //================


        //Pow x,n
        //================
        public double myPow(double x, int n)
        {
            int nAbs = Math.Abs(n);
            double ans = 1;
            double oldAns = double.PositiveInfinity;
            if (n == Int32.MinValue) nAbs = Int32.MaxValue;

            for (int i = 0; i < nAbs; i++)
            {
                ans *= x;
                if (ans == 0) return 0;
                else if (ans >= double.PositiveInfinity)
                {
                    if (n > 0) return double.PositiveInfinity;
                    else return 0;
                }
                else if (ans == Math.Abs(oldAns))
                {
                    if (x <= 0 && n % 2 == 1) return Math.Abs(ans) * (-1);
                    else return ans;
                }
                oldAns = ans;
            }
            if (n < 0 && ans != 0)
            {
                ans = 1 / ans;
            }
            return ans;
        }


        //ZigZag
        //================
        public static String zigZag(String s, int numRows)
        {
            String[] rows = new String[numRows];
            char[] charArray = s.ToCharArray();
            int count = 0;
            int rowAdd = 0;
            Boolean dirDown = true;

            while (count <= s.Length - 1)
            {
                if (rows[rowAdd] == null) rows[rowAdd] = "" + charArray[count];
                else rows[rowAdd] += charArray[count];

                count++;
                if (numRows == 1) { }
                else if (rowAdd >= numRows - 1)
                {
                    rowAdd--;
                    dirDown = false;
                }
                else if (rowAdd <= 0)
                {
                    rowAdd++;
                    dirDown = true;
                }
                else
                {
                    if (dirDown) rowAdd++;
                    else rowAdd--;
                }

            }

            String ans = "";

            for(int i = 0; i < rows.Length; i++)
            {
                if (rows[i] != null) ans += rows[i];
            }

            return ans;
        }


        //IsPowerOfTwo
        //================
        public static Boolean isPowerOfTwo(int n)
        {
            int tmp = 0, tot = 0;

            if (n == 0 || n == Int32.MaxValue) return false;
            while (n > tot)
            {
                tot = (int)(Math.Pow(2, tmp));
                tmp++;
            }

            if (n == tot) return true;
            return false;
        }

        //AddBinary
        //================
        public static String addBinary(String a, String b)
        {
            int len = a.Length;
            int diff = Math.Abs(len - b.Length);

            if (diff == 0) { }
            else if (b.Length > len)
            {
                len = b.Length;
                for (int j = 0; j < diff; j++)
                {
                    a = "0" + a;
                }
            }
            else
            {
                for (int j = 0; j < diff; j++)
                {
                    b = "0" + b;
                }
            }

            String ans = "";
            int carry = 0;
            int newCarry = 0;
            int toAdd = 0;

            for (int i = len - 1; i >= 0; i--)
            {
                char a1 = a[i];
                char b1 = b[i];

                if (a1 == '1' && b1 == '1')
                {
                    newCarry = 1;
                    toAdd = carry;
                }
                else if (a1 == '1' || b1 == '1')
                {
                    if (carry == 1)
                    {
                        newCarry = 1;
                        toAdd = 0;
                    }
                    else
                    {
                        newCarry = 0;
                        toAdd = 1;
                    }
                }
                else
                {
                    newCarry = 0;
                    toAdd = carry;
                }

                ans = "" + toAdd + ans;
                carry = newCarry;
            }
            if (carry == 1) ans = "" + carry + ans;
            return ans;
        }



        private void Log(object sender, LogMessageEventArgs e)
        {
            Console.WriteLine(e.Message);
        }
    }
}
