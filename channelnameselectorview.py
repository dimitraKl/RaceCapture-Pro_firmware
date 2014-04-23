import kivy
kivy.require('1.8.0')
from kivy.uix.boxlayout import BoxLayout
from kivy.app import Builder
from kivy.properties import StringProperty

Builder.load_file('channelnameselectorview.kv')

class ChannelNameSelectorView(BoxLayout):
    rcid = StringProperty('')

    def __init__(self, **kwargs):
        super(ChannelNameSelectorView, self).__init__(**kwargs)
        self.bind(rcid = self.on_rcid)
    
    
    def setValue(self, value):
        self.ids.channelName.text = value
        
    def on_rcid(self, instance, value):
        print("on rcid " + value)