# Code Commenter AI — Video Script (~3 min)

---

**[SCREEN: Show GitHub repo page]**

"Hey everyone! I'm KKS, and today I'm going to show you Code Commenter AI — 
a tool that automatically adds inline comments to competitive programming code."

---

**[SCREEN: Show a raw C++ code snippet — no comments]**

"So if you've ever looked at competitive programming code, you know it looks 
like this — short variable names, no comments, completely unreadable. 
If you're a student trying to learn algorithms, this is a nightmare."

---

**[SCREEN: Open the Gradio app in browser]**

"Code Commenter AI fixes this. You just paste your code, hit 'Add Comments', 
and in a few seconds, every line gets a short, meaningful inline comment."

---

**[SCREEN: Paste a C++ sorting example, click the button, show the result]**

"Let me demo it. Here's a basic sorting problem in C++. 
I paste it in... click Add Comments... and there we go — 
every line now has a clear comment explaining what it does."

---

**[SCREEN: Try a Python example too]**

"It works with Python too. Here's a GCD function — 
paste it in, click the button, and we get clean inline comments."

---

**[SCREEN: Show the architecture diagram from README]**

"How does it work? I fine-tuned Qwen2.5-Coder-7B-Instruct using LoRA — 
that means I only trained 0.53% of the model's parameters. 

The training data comes from 122 GeeksforGeeks algorithm pages — 
I scraped naturally commented code, then used regex to strip the comments 
to create input-output pairs. 569 training examples total.

The whole thing trained in about 72 minutes on a free Colab T4 GPU."

---

**[SCREEN: Show the model running on Colab]**

"For deployment, the model runs on Google Colab with a free T4 GPU. 
It's loaded in 4-bit quantization so it only uses about 4GB of VRAM. 
The LoRA weights are auto-downloaded from HuggingFace Hub.

Zero API calls to OpenAI or Google — everything runs locally, 
so your code stays completely private."

---

**[SCREEN: Show the training loss table from README]**

"Training results — the model converges nicely. 
Training loss went from 0.35 down to 0.019, 
and validation loss settled around 0.084."

---

**[SCREEN: Back to the Gradio app]**

"That's Code Commenter AI — a fine-tuned small language model 
that turns unreadable competitive programming code into 
well-documented, commented code.

Built with Smolify.AI for the Krack Hack Gen AI Challenge.

Links to the GitHub repo and model weights are in the description. 
Thanks for watching!"

---