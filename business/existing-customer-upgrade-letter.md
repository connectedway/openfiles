# Existing-Customer Upgrade Outreach Letter

**Purpose:** Outreach to existing OpenFiles customers on older versions (SMBv2-only or earlier), proposing an upgrade path with a refreshed maintenance agreement.

**Status:** Template draft — customize per recipient before sending.

**Designed for:** Asynchronous, written discovery — works without requiring a phone call. Especially relevant for international customers (e.g., Taiwan) where phone calls are culturally or linguistically friction-heavy.

**Customization checklist:**
- [ ] Insert recipient name, title, company
- [ ] Verify their actual current version of OpenFiles
- [ ] Tailor the technical-context paragraph to their stack and use case
- [ ] Confirm proposed maintenance numbers before sending
- [ ] Note that AD on ThreadX is problematic — frame AD as Linux/desktop story, not as available on their RTOS
- [ ] Attach the OpenFiles data sheet (`openfiles-datasheet.md`)
- [ ] Consider sending a parallel Mandarin translation for Taiwan recipients (professional translation, ~$200-400 for a one-pager); flag in the email cover that English + Mandarin versions are both attached

---

**Subject:** OpenFiles upgrade path and refreshed maintenance proposal

Dear [name],

Thank you for being a long-standing OpenFiles customer. The maintenance relationship between [Customer] and Connected Way is one of our most valued continuous engagements, and your products' reach in the global imaging market — through the consumer brands that rebrand your platforms — has been a meaningful reference for our work.

I am writing to propose an upgrade path that I believe matters to both of us.

## Why I am raising this now

Your current OpenFiles deployment is built on the SMBv2-era branch. This branch has served you well, but the SMB environment has changed in ways that affect your products in the field.

- Modern Windows and macOS no longer prefer SMBv2. Windows 11 and recent macOS versions refuse SMBv2 in some configurations. End users connecting your products to current Windows or Mac systems may not get SMB connectivity that works without effort.
- SMBv2 has known security weaknesses. OEM security audits increasingly flag SMBv2-only stacks as out of compliance.
- The current OpenFiles release has expanded significantly: modern SMB3.x with AES-CCM and AES-GCM encryption, full Active Directory integration on Linux and desktop platforms, DFS, multi-channel, and broader RTOS support — with ongoing security work focused on this current branch.

## Why I care about this

OpenFiles powers your products in the field. When end users experience SMB problems because the underlying stack is from an earlier era, that reflects on OpenFiles itself. I would rather have you on a stack that works cleanly in modern environments than collect maintenance on something becoming fragile. **Your product is our reference**, and I care that it is seen working well.

## A few questions to help us proceed

So we can understand your current situation, it would help us if you could share — by email, at your convenience — the following:

1. Are your products still actively using OpenFiles, or is the deployment now primarily legacy?
2. Have any end users reported SMB connectivity issues (especially with Windows 11 or recent macOS)?
3. Are you planning new products that will require SMB connectivity?
4. Is your engineering team available for an upgrade integration, or would it be easier if we handled the integration work?

Your answers will let us shape the proposal to fit your actual situation, not assumptions.

## Three options to consider

**Option 1 — Status quo on the legacy branch.** Current maintenance agreement continues at $2,500/year. Existing defect fixes remain available. Going forward, our maintenance investment is consolidating on the current OpenFiles release — new security work, protocol updates, and platform support will be on the current branch.

**Option 2 — Free software upgrade with refreshed maintenance.** We provide the current OpenFiles release at no additional license cost.

**The upgrade is structured as a drop-in replacement.** We preserve the OpenFiles API surface from your current branch. The new stack swaps in against your existing integration code without requiring a rewrite. In our experience this is the single largest barrier to embedded-component upgrades, and we have engineered around it.

Refreshed maintenance: **$10,000/year**, covering active support — ongoing security work, modern SMB3.x feature evolution, platform support, and direct engineering response.

**For context on this rate:** commercial SMB stack maintenance from other vendors typically runs $100,000 per year or more for active support of comparable scope. The increase from $2,500 reflects substantial scope expansion since the original agreement (DFS, AD, modern crypto, multi-channel, broader RTOS support — most of which did not exist when the agreement was signed) and more than a decade of operational cost growth. The proposed rate remains a fraction of what equivalent commercial support costs.

**Option 2A — Integration support add-on (optional).** Even with the drop-in API, some customers prefer that we handle the upgrade integration directly — to free internal engineering bandwidth or for a clean managed transition. We can offer a **$20,000 NRE for integration**: approximately two weeks of focused engineering, contingent on your providing a development board and access to your development environment. This bundles cleanly with Option 2.

**Option 3 — Custom commercial arrangement.** If a different shape fits better — multi-year commitment, OEM-specific feature work, alternative pricing structure — we are open to discussion.

## Next step

Replying by email is welcome and easiest for both sides. If a video or phone call would be useful at any point, we can arrange one in your preferred language with a translator if helpful, but email correspondence works equally well for us.

The current OpenFiles data sheet is attached for reference. Your deployment is included as an anonymized reference customer — your products' rebrand reach is a story we are genuinely proud to point at.

Best regards,

Richard Schmitt
Founder, Connected Way
[email] | [phone]
connectedway.com

---

## Editorial notes

- **Written for asynchronous, written discovery.** Phone-call asks have been removed from the body. The "Next step" paragraph explicitly normalizes email-only correspondence and accommodates language preferences without making them feel like a special accommodation.
- **"A few questions to help us proceed" section is the new discovery embed.** Replaces the phone-call discovery I'd recommended earlier. Four focused questions that surface what you actually need to know — whether the deployment is active or legacy, whether they're experiencing SMB issues, whether new products are coming, and whether they want us to do the integration.
- **The $100K commercial-stack comparison anchors the maintenance rate.** $10K against $2,500 looks aggressive in isolation. $10K against $100K (the real alternative-vendor market) looks modest. This calibration is the most important rhetorical move in the entire letter.
- **Simpler English throughout.** Shorter sentences, fewer idioms, clearer transitions. Reads cleanly for a non-native English speaker without being condescending.
- **AD is positioned as Linux/desktop only.** AD on ThreadX is problematic; do not promise it.
- **Drop-in API replacement is the headline of Option 2.** Most adoption fear is "how much code do we have to rewrite" — naming the answer ("none, where feasible") changes the cost/risk math more than anything else in the proposal.

## Discovery is now embedded — sequence becomes simpler

Original suggested sequence was: soft phone discovery → formal letter. With the embedded questions, the sequence collapses to:

1. **Send the letter** (with attached data sheet, optionally with Mandarin translation)
2. **Wait for written reply** — their answers to the four discovery questions will tell you whether this is an active deployment, a legacy product, or something between
3. **Tailor follow-up to their answers** — if SMB works fine, push the upgrade; if it doesn't work and they don't care, soft-pedal; if they want us to do the work, push Option 2A; if they want to chat, offer a translator-assisted call

This is lower-risk for international customers where phone discovery isn't practical.

## Risks to manage in follow-up

- **They might not reply at all.** Common with international, language-constrained customers. Follow up in 3-4 weeks with a short email; do not assume silence means no.
- **They might pick Option 1** and you have effectively locked yourself out of pushing again later. Counter: "consolidating investment on current stack" preserves future EOL optionality. You can revisit in 12-18 months with concrete deprecation if needed.
- **They might walk entirely.** If $2,500/year is genuinely insurance for them, the discussion itself might cause them to reassess. Be prepared — it is better to know than to keep collecting from a customer about to drop the line.
- **Option 2 negotiation.** Realistic landing: $6-8K maintenance. $5K is the lowest justifiable rate for active maintenance on the current stack. The $100K comparison gives you negotiation room — if they push back at $10K, you can move to $7-8K while pointing out commercial alternatives are 10x+ higher.
- **NRE scope creep.** Two weeks is a real estimate. Protect against scope expansion: SOW should specify "integration of [current OpenFiles version] onto [customer platform], delivery of working build with [defined acceptance criteria]." Anything beyond that is change-order territory.
- **Translation cost.** If you want a Mandarin parallel version of the letter, professional translation (not machine translation) is recommended — typically $0.10-0.20/word, so $50-100 for the letter and $200-400 for the data sheet. Cheap insurance for an important customer.
