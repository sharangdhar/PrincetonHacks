import sys, time
sys.path.append('D:\\Documents\\LeapDeveloperKit\\LeapSDK\\lib')
sys.path.append('D:\\Documents\\LeapDeveloperKit\\LeapSDK\\lib\\x86')

import Leap

class LeapListener(Leap.Listener):
    def on_frame(self, controller):
        frame = controller.frame()
        if not frame.hands.is_empty:
            # Get the first hand
            self.hand = frame.hands[0]
            self.normal = self.hand.palm_normal
            print self.normal.x
    def get_x(self, controller):
        return -self.normal.x

def main():
    # Create a sample listener and controller
    listener = LeapListener()
    controller = Leap.Controller()

    # Have the sample listener receive events from the controller
    controller.add_listener(listener)
    listener.hand = 2

    while(True):
        print listener.normal.x
        time.sleep(1)

    # Keep this process running until Enter is pressed
    print "Press Enter to quit..."
    sys.stdin.readline()
	
    # Remove the sample listener when done
    controller.remove_listener(listener)


if __name__ == "__main__":
    main()

