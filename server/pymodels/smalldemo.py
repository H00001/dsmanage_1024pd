#!/tec/python
import requests
import sys
resp = requests.get(sys.argv[1])
print(resp.text)

