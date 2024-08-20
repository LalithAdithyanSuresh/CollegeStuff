
from crew import Crew, Agent, Task


# Define agents
SoftwareBot = Agent(name="Software",role="To produce a solution for instruction on the given query related to the software of the tesla car screen",goal="Steps on how to achieve the task by traversing the menus on the tesla screen")

HardwareBot = Agent(name="Hardware",role="To produce solution for instruction on the given query related to the hardware components of the tesla car",goal="Steps on how to fix,clean and maintain the car's hardware components")

GrammarChecker = Agent(name="Grammar",role="To Check the grammer, readability of the given prompt and produce a simple output",goal="To produce a easy to read text using the given prompt")

BasicChatBot = Agent(name="Basic",role="To start, end the conversation with the user",goal="To make it feel like they're talking with a human rather than a bot.")

selector = Agent(name="Selction",role="To choose if the given prompt is hardware or software related of a tesla car",goal="The response should be only Software or Hardware")
# Define task
def StartChat(msg):
  # Researcher gathers information
    opt = selector.ask(msg)
    if(opt == 'Hardware'):
        response = HardwareBot.ask(msg)

  # Writer summarizes the information
    out = GrammarChecker.ask("Check if this response is grammatically correct and simple to read : " + response)
    return out

# Create and run the Crew
task = Task(description="Act as a customer support agent", function=StartChat, args=["How do i turn on my tesla's blinkers"])
crew = Crew(agents=[SoftwareBot,HardwareBot,GrammarChecker,BasicChatBot], tasks=[task])
result = crew.run()

print(f"Summary: {result}")