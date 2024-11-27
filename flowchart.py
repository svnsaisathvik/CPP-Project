from graphviz import Digraph

dot = Digraph()

# User Flow
dot.node('A', 'User Logs In')
dot.node('B', 'Options: Signup or Login')
dot.node('C', 'Check Previous Bookings or Continue New Booking')
dot.node('D', 'Display Previous Bookings')
dot.node('E', 'Display Available Movies')
dot.node('F', 'Select Movie')
dot.node('G', 'Select Date')
dot.node('H', 'Display Theatres and Shows')
dot.node('I', 'Select Show')
dot.node('J', 'Display Seat Layout')
dot.node('K', 'Select Seat (Row & Column)')
dot.node('L', 'Verify Availability')
dot.node('M', 'Book Ticket Successfully')

# Define edges individually
dot.edge('A', 'B')
dot.edge('B', 'C')
dot.edge('C', 'D', label='Check Previous Bookings')
dot.edge('C', 'E', label='Continue New Booking')
dot.edge('E', 'F')
dot.edge('F', 'G')
dot.edge('G', 'H')
dot.edge('H', 'I')
dot.edge('I', 'J')
dot.edge('J', 'K')
dot.edge('K', 'L')
dot.edge('L', 'M', label='Available')
dot.edge('L', 'J', label='Not Available')

# Admin Flow
dot.node('Admin', 'Admin Logs In')
dot.node('N', 'Enter Secret Pass Key')
dot.node('O', 'Admin Options')
dot.node('P', 'Add Theatre')
dot.node('Q', 'Add Show')
dot.node('R', 'Delete Movie')
dot.node('S', 'Delete Show')
dot.node('T', 'Delete Theatre')

# Define Admin edges
dot.edge('Admin', 'N')
dot.edge('N', 'O')
dot.edge('O', 'P', label='Add Theatre')
dot.edge('O', 'Q', label='Add Show')
dot.edge('O', 'R', label='Delete Movie')
dot.edge('O', 'S', label='Delete Show')
dot.edge('O', 'T', label='Delete Theatre')

# Render the graph
dot.render('flowchart', format='png')
