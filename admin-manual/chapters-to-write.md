
## describe signing (setup)

## describe security & user bootstrap

## describe automatic task and submission closings (ecs cleanup)

## describe the generated pdf's

+ pdf's:
    + with ec_head:
```
templates/checklists/wkhtml2pdf/checklist.html:    {% include 'wkhtml2pdf/ec_head.inc' %}
templates/meetings/email/agenda.html:    {% include 'wkhtml2pdf/ec_head.inc' %}
templates/meetings/wkhtml2pdf/agenda.html:    {% include 'wkhtml2pdf/ec_head.inc' %}
templates/meetings/wkhtml2pdf/protocol.html:    {% include 'wkhtml2pdf/ec_head.inc' %}
templates/meetings/wkhtml2pdf/timetable.html:    {% include 'wkhtml2pdf/ec_head.inc' %}
templates/meetings/wkhtml2pdf/vote.html:{% include 'wkhtml2pdf/ec_head.inc' %}
templates/notifications/answers/wkhtml2pdf/base.html:    {% include 'wkhtml2pdf/ec_head.inc' %
```
    + without ec_head:
```
templates/meetings/email/timetable.html:{% extends 'wkhtml2pdf/skeleton.html' %}
templates/meetings/wkhtml2pdf/vote_preview.html:{% extends 'wkhtml2pdf/skeleton.html' %}
templates/notifications/wkhtml2pdf/base.html:{% extends 'wkhtml2pdf/skeleton.html' %}
templates/submissions/wkhtml2pdf/view.html:{% extends 'wkhtml2pdf/skeleton.html' %}
```

## describe the types of messages the ecs sends
```
git grep "send_.*message" | grep -v "from.*import" | grep -v "def.*(.*):"
```

+ emails from text template: find . -name "*.txt"
```
templates/submissions/presenter_change_new.txt
templates/submissions/acknowledge_message.txt
templates/submissions/change_message.txt
templates/submissions/new_version_message.txt
templates/submissions/creation_message.txt
templates/submissions/presenter_change_previous.txt
templates/submissions/susar_presenter_change_new.txt
templates/submissions/susar_presenter_change_previous.txt
templates/submissions/decline_message.txt
templates/submissions/vote_publish.txt
templates/users/new_signing_user.txt
templates/users/indisposed_proxy.txt
templates/users/division_of_work.txt
templates/search/indexes/help/page_text.txt
templates/checklists/external_review_publish.txt
templates/checklists/external_review_declined.txt
templates/checklists/external_reviewer_invitation.txt
templates/notifications/answers/new_message.txt
templates/communication/mail/digest.txt
templates/msg_core.txt
templates/meetings/email/basg.txt
templates/meetings/messages/primary_investigator_invitation.txt
templates/meetings/messages/expedited_reviewer_invitation.txt
```

+ emails from html template: find . -name "*email.html"
```
templates/users/registration/activation_email.html
templates/users/invitation/invitation_email.html
templates/users/password_reset/reset_email.html
templates/users/password_reset/register_email.html
```

+ python code sending non template emails:
```
git grep "send_.*message" | grep -v "from.*import" | grep -v "def.*(.*):"  | grep -v "/.*\.txt" | grep -v send_message_on_close | grep -v message_template |grep -v tests.py | sort | uniq | manual filter
ecs/core/views/submissions.py
ecs/documents/tasks.py
ecs/tasks/tasks.py
ecs/votes/tasks.py
```
