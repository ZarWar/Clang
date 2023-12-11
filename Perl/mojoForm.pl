use Mojolicious::Lite -signatures;

get '/' => 'form';

# PUT  /nothing
# POST /nothing?_method=PUT
put '/nothing' => sub ($c) {

  # Prevent double form submission with redirect
  my $value = $c->param('whatever');
  $c->flash(confirmation => "We did nothing with your value ($value).");
  $c->redirect_to('form');
};

app->start;
__DATA__

@@ form.html.ep
<!DOCTYPE html>
<html>
  <body>
    % if (my $confirmation = flash 'confirmation') {
      <p><%= $confirmation %></p>
    % }
    %= form_for nothing => begin
      %= text_field whatever => 'I ♥ Mojolicious!'
      %= submit_button
    % end
  </body>
</html>