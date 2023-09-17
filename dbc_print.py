import cantools
from pprint import pprint

db = cantools.database.load_file('example.dbc')
print(db.messages)
my_message = db.get_message_by_name('MyMessage')
pprint(my_message.signals)