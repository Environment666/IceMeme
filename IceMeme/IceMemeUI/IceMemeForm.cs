using FastColoredTextBoxNS;
using System;
using System.Drawing;
using System.IO;
using System.Text.RegularExpressions;
using System.Threading;
using System.Windows.Forms;

namespace IceMemeUI
{
    public partial class IceMemeForm : Form
    {
        public IceMemeForm()
        {
            InitializeComponent();
            //TopMost Enabled by default
            TopMost = true;
        }
        //clear button click event
        private void Clear_Click(object sender, EventArgs e) => LuaCBox.Clear();//this clear all the text in luac richtextbox
        //execute button click event
        private void Execute_Click(object sender, EventArgs e)
        {
            if (NamedPipes.NamedPipeExist(NamedPipes.scriptpipe))//check if the pipe exist
            {
                new Thread(() =>//lets run this in another thread so if roblox crash the ui/gui don't freeze
                {
                    string[] array = LuaCBox.Text.Split("\r\n".ToCharArray());//array to store all and split the script
                    for (int i = 0; i < array.Length; i++)//for loop to send all the lines
                    {
                        string script = array[i];
                        try
                        {
                            NamedPipes.LuaCPipe(script);//lua c pipe function to send the array
                        }
                        catch (Exception ex)
                        {
                            MessageBox.Show(ex.Message.ToString());//if there any error a messagebox will pop up with the error
                        }
                    }
                }).Start();
            }
            else
            {
                MessageBox.Show("Inject " + Functions.exploitdll + " before Using this!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);//if the pipe can't be found a messagebox will appear
                return;
            }
        }
        //send button click event
        private void Send_Click(object sender, EventArgs e)
        {
            if (CmdTextBox.Text.ToLower() == "cmds")//check if the user send cmds so we can display the commands
            {
                CmdBox.AppendText(Functions.TextToBox[0]);//Append text to the command richtextbox
                CmdTextBox.Clear();//clear the command textbox
            }
            else if (CmdTextBox.Text.ToLower() == "credits")//check if the user send credits so we can display the credits
            {
                CmdBox.AppendText(Functions.TextToBox[1]);//Append text to the command richtextbox
                CmdTextBox.Clear();//clear the command textbox
            }
            else if (CmdTextBox.Text.ToLower() == "clear")
            {
                CmdBox.Clear();
                CmdTextBox.Clear();
            }
            else
            {
                NamedPipes.CommandPipe(CmdTextBox.Text);//command pipe function to send the text in the command textbox
                CmdTextBox.Clear();//clear the command textbox
            }
        }
        //command richtextbox textchanged event
        private void CmdBox_TextChanged(object sender, EventArgs e)
        {
            CmdBox.SelectionStart = CmdBox.Text.Length;//this get all the text
            CmdBox.ScrollToCaret();//so with this we can scroll to the bottom
        }
        //command textbox keydown event
        private void CmdTextBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)//if user pressed Key Enter
            {
                Send_Click(sender, e);//execute Send_click function
            }
        }
        //open button click event
        private void Open_Click(object sender, EventArgs e)
        {
            if (Functions.openfiledialog.ShowDialog() == DialogResult.OK)//check if the user clicked Ok/open
            {
                try
                {
                    LuaCBox.Text = File.ReadAllText(Functions.openfiledialog.FileName);//load all the text in the lua c rightextbox

                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error: Could not read file from disk. Original error: " + ex.Message);//display if got error
                }
            }
        }
        //inject button click event
        public void Inject_Click(object sender, EventArgs e) => Functions.Inject();

        private void Btools_Click(object sender, EventArgs e) => NamedPipes.CommandPipe("btools me");

        private void FF_Click(object sender, EventArgs e) => NamedPipes.CommandPipe("ff me");

        private void Ws_Click(object sender, EventArgs e) => NamedPipes.CommandPipe("ws me " + WalkSpeedValue.Value);

        private void Suicide_Click(object sender, EventArgs e) => NamedPipes.CommandPipe("kill me");

        private void Sit_Click(object sender, EventArgs e) => NamedPipes.CommandPipe("sit me");

        private void JP_Click(object sender, EventArgs e) => NamedPipes.CommandPipe("jp me " + JumpPowerValue.Value);

        private void TopCheck_CheckedChanged(object sender, EventArgs e)
        {
            if (TopCheck.Checked)
            {
                TopMost = true;
            }
            else
            {
                TopMost = false;
            }
        }

        private int thm;

        public void UpdateColorControls(Control theui)
        {
            Color Black = Color.FromName("Black");
            Color White = Color.FromName("White");
            
            switch (thm)
            {
                case 1:
                    theui.BackColor = Black;
                    theui.ForeColor = White;
                    this.BackColor = Black;
                    this.Text = "IceMeme UI Dark Theme";
                    break;
                case 0:
                    theui.BackColor = White;
                    theui.ForeColor = Black;
                    this.BackColor = White;
                    this.Text = "IceMeme UI Light Theme";
                    break;
            }

            foreach (Control subC in theui.Controls)
            {
                UpdateColorControls(subC);
            }
        }

        private void Theme_Click(object sender, EventArgs e)
        {
            foreach (Control c in this.Controls)
            {
                UpdateColorControls(c);
            }
            thm++;
            if (thm > 1) thm = 0;
        }

        private void IceSourceForm_FormClosed(object sender, FormClosedEventArgs e) => Application.Exit();

        private void Executelua_Click(object sender, EventArgs e)
        {
            if (NamedPipes.NamedPipeExist(NamedPipes.luapipe))//check if the pipe exist
            {
                NamedPipes.LuaPipe(LuaBox.Text);
            }
            else
            {
                MessageBox.Show("Inject " + Functions.exploitdll + " before Using this!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);//if the pipe can't be found a messagebox will appear
                return;
            }
        }

        private void Clearlua_Click(object sender, EventArgs e) => LuaBox.Clear();

        private void Openlua_Click(object sender, EventArgs e)
        {
            if (Functions.openfiledialog.ShowDialog() == DialogResult.OK)//check if the user clicked Ok/open
            {
                try
                {
                    LuaBox.Text = File.ReadAllText(Functions.openfiledialog.FileName);//load all the text in the lua c rightextbox

                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error: Could not read file from disk. Original error: " + ex.Message);//display if got error
                }
            }
        }
        Style SalmonStyle = new TextStyle(Brushes.Salmon, null, FontStyle.Italic);
        Style OrangeStyle = new TextStyle(Brushes.Orange, null, FontStyle.Italic);
        Style LimeGreenStyle = new TextStyle(Brushes.LimeGreen, null, FontStyle.Italic);
        Style CyanStyle = new TextStyle(Brushes.Cyan, null, FontStyle.Italic);
        Style SpringGreenStyle = new TextStyle(Brushes.SpringGreen, null, FontStyle.Italic);
        Style SkyBlueStyle = new TextStyle(Brushes.SkyBlue, null, FontStyle.Italic);
        Style PaleGoldenrodStyle = new TextStyle(Brushes.PaleGoldenrod, null, FontStyle.Italic);
        Style FirebrickStyle = new TextStyle(Brushes.Firebrick, null, FontStyle.Italic);
        Style GoldBlueStyle = new TextStyle(Brushes.Gold, null, FontStyle.Italic);
        Style CoralStyle = new TextStyle(Brushes.Coral, null, FontStyle.Italic);

        private void LuaCBox_TextChanged(object sender, FastColoredTextBoxNS.TextChangedEventArgs e)
        {
            e.ChangedRange.ClearStyle(SalmonStyle);
            e.ChangedRange.ClearStyle(OrangeStyle);
            e.ChangedRange.ClearStyle(LimeGreenStyle);
            e.ChangedRange.ClearStyle(CyanStyle);
            e.ChangedRange.ClearStyle(SpringGreenStyle);
            e.ChangedRange.ClearStyle(SkyBlueStyle);
            e.ChangedRange.ClearStyle(PaleGoldenrodStyle);
            e.ChangedRange.ClearStyle(FirebrickStyle);
            e.ChangedRange.ClearStyle(GoldBlueStyle);
            e.ChangedRange.ClearStyle(CoralStyle);
            e.ChangedRange.SetStyle(SalmonStyle, @"getglobal", RegexOptions.Multiline);
            e.ChangedRange.SetStyle(OrangeStyle, @"getfield", RegexOptions.Multiline);
            e.ChangedRange.SetStyle(LimeGreenStyle, @"pushnumber", RegexOptions.Multiline);
            e.ChangedRange.SetStyle(CyanStyle, @"setfield", RegexOptions.Multiline);
            e.ChangedRange.SetStyle(SpringGreenStyle, @"pushvalue", RegexOptions.Multiline);
            e.ChangedRange.SetStyle(SkyBlueStyle, @"pushstring", RegexOptions.Multiline);
            e.ChangedRange.SetStyle(PaleGoldenrodStyle, @"pushnumber", RegexOptions.Multiline);
            e.ChangedRange.SetStyle(FirebrickStyle, @"emptystack", RegexOptions.Multiline);
            e.ChangedRange.SetStyle(GoldBlueStyle, @"getservice", RegexOptions.Multiline);
            e.ChangedRange.SetStyle(CoralStyle, @"pushboolean", RegexOptions.Multiline);
        }
    }
}
