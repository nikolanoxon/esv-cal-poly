#Checkout Code from the Repository

# The Subversion Repository #
Subversion (SVN) is a method which allows us to keep current/previous versions of documents and source code in a single, centralized, online location. This server space is available to all group members on any computer which is running a subversion client. In order to access the files, a subversion client must be installed - I use Tortoise SVN. You will also need a username and password to access the repository. Your username is the email associated with this repository (mine is nikolanoxon@gmail.com for example). Your password can be found by following this link: https://code.google.com/hosting/settings


---

## Installing Tortoise SVN ##
Go to: http://tortoisesvn.net/downloads.html

Download the link "Tortoise-SVN" (either 32 or 64 bit depending on your system)

Run the installer and follow the instructions

Setup should complete and ask to restart.

## Installing Rapid SVN ##
Go to: http://rapidsvn.tigris.org/

Download the lastest release from the link "download the latest release"

Run the installer and follow the instructions


---

## Checking out the Subversion Repository on your Computer ##

Make an empty folder where you want to checkout the repository, referred to as "ESV Repository" in these instructions.

Right-click on the ESV Repository folder and select “SVN Checkout…”

Paste the repository URL: https://esv-cal-poly.googlecode.com/svn/trunk/esv-cal-poly

Note: With RapidSVN and TortoiseSVN you must use a secure URL to be able to commit to to the repository. If you do not use a secure URL, your svn client will give a 403 or 405 connection/activity error upon committing.

Leave the other options at their defaults: Fully recursive checked, HEAD revision selected.

Click OK and wait for the files to download. The client will ask you for a username and password. If you followed the "Installing Tortoise SVN" instructions, you should have these.


---

## Editing and Committing files to the Subversion Client ##

WARNING: Copying and deleting files that are in the repository should ONLY be done using the right-click Tortoise SVN commands. Doing otherwise will create reversion errors, duplicate files, and a potential loss of work.

Files created and/or edited since your last checkout MUST be committed. Otherwise they will not be uploaded to the repository. Right click on the ESV Repository folder and select “SVN Checkout…”

Select all edited and new files which you want saved to the repository.

Click OK and wait for checkout to complete.

To test that you have successfully committed your files, create a new test folder and checkout the repository to it. If your new files are included then you have successfully committed your files.



#### Instructions taken from the Cal Poly Robotics Club website ####