from openai import OpenAI

client = OpenAI(api_key='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')

stream = client.chat.completions.create(
    model="gpt-3.5-turbo-0613",
    messages=[{"role": "user", "content": "Say this is a test"}],
    stream=True,
)
for chunk in stream:
    if chunk.choices[0].delta.content is not None:
        print(chunk.choices[0].delta.content, end="")

curl https://chatgpt-api.shn.hk/v1/ -H 'Content-Type: application/json' -d '{ "model": "gpt-3.5-turbo", "messages": [{"role": "user", "content": "Hello, how are you?"}]}'


