import wikipedia
import re
import hashlib

hash = "a173ac6edc5bd9f6ef350544a5b054e1188486ba9d78fbc8fe7d5a4c4cde9657"

moth_page = wikipedia.page("'Moth'")

moth_text = moth_page.content

moth_sentences = re.split(r'\.\s', moth_text)

for sentence in moth_sentences:
	if hashlib.sha256(bytes(sentence, "utf-8")).hexdigest() == hash:
		print(sentence)
