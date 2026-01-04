# Connect to GitHub with VSCode (WSL Environment)

## Prerequisites
Before you begin, ensure you have the following:
- Visual Studio Code installed on your Windows machine. [Download VS Code here](https://code.visualstudio.com/)
- WSL (Windows Subsystem for Linux) installed and running (e.g., Ubuntu).
- Git installed **inside your WSL distribution** (run `sudo apt install git` in your WSL terminal).
- A GitHub account.

## Steps to Connect to GitHub

1. **Install Necessary Extensions**
   - Open VSCode on Windows.
   - Go to the Extensions view (Sidebar icon or `Ctrl+Shift+X`).
   - Search for and install the **WSL** extension (by Microsoft).
   - Search for and install the **GitHub Pull Requests and Issues** extension.

2. **Connect VSCode to WSL**
   - Open your WSL terminal (e.g., Ubuntu).
   - Navigate to your project directory or home folder.
   - Type `code .` and hit Enter. This launches VSCode connected to your WSL environment.
   - Alternatively, in VSCode, click the blue remote indicator (bottom left corner), select `WSL: Connect to WSL`, and wait for the connection to establish.

3. **Sign in to GitHub**
   - Once VSCode is running in WSL mode (you should see "WSL: Ubuntu" in the bottom left), open the Command Palette (`Ctrl+Shift+P`).
   - Type `GitHub: Sign in` and select the option.
   - Follow the browser prompts to authenticate. VSCode will bridge the authentication from Windows to your WSL instance.

4. **Clone a Repository**
   - In the VSCode window connected to WSL, open the Command Palette.
   - Type `Git: Clone` and select the option.
   - Paste the URL of your GitHub repository.
   - **Crucial:** Ensure you choose a folder inside your WSL file system (e.g., `/home/username/projects`) rather than a Windows mount path (`/mnt/c/...`) for better performance.

5. **Open the Repository**
   - Once cloned, VSCode will prompt you to open the repository.
   - Click `Open`. The window will reload, keeping you connected to WSL.

6. **Make Changes and Commit**
   - Edit files as needed using VSCode's editor.
   - Go to the Source Control view in the sidebar.
   - Stage your changes, write a commit message, and commit.

7. **Push Changes to GitHub**
   - After committing, click the `Sync Changes` button in the Source Control view.
   - This will push your changes to GitHub using the Git configuration inside WSL.

## Additional Tips
- **Launch from Terminal:** The easiest way to open a project is typing `code .` directly inside your WSL terminal in the desired folder.
- **Credential Helper:** VSCode automatically handles Git credentials between Windows and WSL, so you usually don't need to configure SSH keys manually for basic HTTPS operations.
- **Performance:** Always keep your source code in the Linux file system (e.g., `~/`), not on the Windows drive (`/mnt/c/`), to avoid slow file operations.
